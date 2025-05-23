import os
import json
import networkx as nx
import pydot
from networkx.drawing.nx_pydot import from_pydot

def load_dot_content(dot_content):
    graphs = pydot.graph_from_dot_data(dot_content)
    if not graphs:
        return nx.DiGraph()  # Return an empty graph if no graphs are found
    graph = graphs[0]
    return from_pydot(graph)

def consolidate_nodes(graph):
    consolidated_graph = nx.DiGraph()
    for u, v in graph.edges():
        u_base = u.split(":")[0]
        v_base = v.split(":")[0]
        consolidated_graph.add_edge(u_base, v_base)
    return consolidated_graph

def compute_dominators(graph, start_node):
    return nx.immediate_dominators(graph, start_node)

def find_back_edges(graph, dominators):
    back_edges = []
    for u, v in graph.edges():
        if dominators.get(u) == v:
            back_edges.append((u, v))
    return back_edges

def identify_loops(graph, back_edges):
    loops = []
    for source, target in back_edges:
        loop = set([target])
        stack = [source]
        while stack:
            node = stack.pop()
            if node not in loop:
                loop.add(node)
                stack.extend(pred for pred in graph.predecessors(node) if pred not in loop)
        loops.append(loop)
    return loops

def collect_graph_elements(dot_content):
    graph = load_dot_content(dot_content)
    consolidated_graph = consolidate_nodes(graph)

    # Check if the consolidated graph is empty
    if not consolidated_graph.nodes():
        return {
            "overall_nodes": [],
            "overall_edges": [],
            "loop_nodes": [],
            "loop_edges": [],
            "branch_nodes": [],
            "branch_edges": [],
            "directed_edges": [],
        }

    # Overall nodes and edges
    overall_nodes = list(consolidated_graph.nodes())
    overall_edges = list(consolidated_graph.edges())

    # Compute dominators
    start_node = overall_nodes[0]
    dominators = compute_dominators(consolidated_graph, start_node)

    # Find back edges
    back_edges = find_back_edges(consolidated_graph, dominators)

    # Identify loop nodes and loop edges
    loop_nodes = set()
    loop_edges = set()
    loops = identify_loops(consolidated_graph, back_edges)
    for loop in loops:
        loop_nodes.update(loop)
        for node in loop:
            for successor in consolidated_graph.successors(node):
                if successor in loop:
                    loop_edges.add((node, successor))

    # Identify branch nodes and branch edges
    branch_nodes = set()
    branch_edges = set()
    for node in consolidated_graph.nodes():
        successors = list(consolidated_graph.successors(node))
        if len(successors) > 1:
            branch_nodes.add(node)
            for successor in successors:
                branch_edges.add((node, successor))

    # Calculate directed edges
    directed_edges = set(overall_edges) - loop_edges - branch_edges

    return {
        "overall_nodes": overall_nodes,
        "overall_edges": overall_edges,
        "loop_nodes": list(loop_nodes),
        "loop_edges": list(loop_edges),
        "branch_nodes": list(branch_nodes),
        "branch_edges": list(branch_edges),
        "directed_edges": list(directed_edges),
    }

def process_dot_files(directory, output_json):
    results = {}
    for file_name in os.listdir(directory):
        if file_name.endswith(".dot"):
            file_path = os.path.join(directory, file_name)
            with open(file_path, 'r') as file:
                dot_content = file.read()

            counts = collect_graph_elements(dot_content)
            results[file_name] = counts

    with open(output_json, 'w') as json_file:
        json.dump(results, json_file, indent=4)

if __name__ == "__main__":
    directory = "./"  # Replace with your actual directory path
    output_json = "output_results.json"  # Output JSON file
    process_dot_files(directory, output_json)
    print(f"Results have been written to {output_json}")

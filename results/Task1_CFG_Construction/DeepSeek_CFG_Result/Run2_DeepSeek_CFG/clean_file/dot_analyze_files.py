import os
import csv
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

def count_graph_elements(dot_content):
    graph = load_dot_content(dot_content)
    consolidated_graph = consolidate_nodes(graph)

    # Check if the consolidated graph is empty
    if not consolidated_graph.nodes():
        return {
            "overall_nodes": 0,
            "overall_edges": 0,
            "loop_nodes": 0,
            "loop_edges": 0,
            "branch_nodes": 0,
            "branch_edges": 0,
        }

    # Overall nodes and edges
    overall_nodes = len(consolidated_graph.nodes())
    overall_edges = len(consolidated_graph.edges())

    # Compute dominators
    start_node = list(consolidated_graph.nodes())[0]
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

    return {
        "overall_nodes": overall_nodes,
        "overall_edges": overall_edges,
        "loop_nodes": len(loop_nodes),
        "loop_edges": len(loop_edges),
        "branch_nodes": len(branch_nodes),
        "branch_edges": len(branch_edges),
    }

def process_dot_files(directory, output_csv):
    with open(output_csv, mode='w', newline='') as csv_file:
        fieldnames = [
            "file_name", "overall_nodes", "overall_edges",
            "loop_nodes", "loop_edges", "branch_nodes", "branch_edges"
        ]
        writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
        writer.writeheader()

        for file_name in os.listdir(directory):
            if file_name.endswith(".dot"):
                file_path = os.path.join(directory, file_name)
                with open(file_path, 'r') as file:
                    dot_content = file.read()

                counts = count_graph_elements(dot_content)
                counts["file_name"] = file_name
                writer.writerow(counts)

if __name__ == "__main__":
    directory = "./"  # Replace with your actual directory path
    output_csv = "output_results.csv"  # Output CSV file
    process_dot_files(directory, output_csv)
    print(f"Results have been written to {output_csv}")

import os
import networkx as nx
import csv

def is_dot_file_complete(graph):
    """Check if the graph has both nodes and edges defined."""
    if len(graph.nodes()) == 0 or len(graph.edges()) == 0:
        return False
    return True

def compare_graphs(test_graph, golden_graph):
    test_nodes = set(test_graph.nodes())
    golden_nodes = set(golden_graph.nodes())
    
    test_edges = set(test_graph.edges())
    golden_edges = set(golden_graph.edges())
    
    # Reasonable conditions
    missing_nodes = golden_nodes - test_nodes
    extra_nodes = test_nodes - golden_nodes
    
    missing_edges = golden_edges - test_edges
    extra_edges = test_edges - golden_edges
    
    reasonable = True
    incorrect = False

    # Reasonable checks
    if len(missing_nodes) > 1 or len(missing_edges) > 1:
        reasonable = False
    
    # Incorrect checks
    if len(extra_nodes) > 0 or len(extra_edges) > 0:
        incorrect = True
    
    # Quantifying incorrectness
    incorrectness_score = len(extra_nodes) + len(extra_edges)

    if not is_dot_file_complete(test_graph):
        return "Uncompleted", incorrectness_score
    elif incorrect:
        return "Incorrect", incorrectness_score
    elif reasonable:
        return "Reasonable", incorrectness_score
    else:
        return "Not Reasonable", incorrectness_score

def load_graph_from_dot(dot_file):
    return nx.drawing.nx_pydot.read_dot(dot_file)

def process_all_dot_files(test_dir, golden_dir, output_csv):
    results = []
    
    for i in range(164):  # Assuming you have 164 pairs
        test_dot_file = os.path.join(test_dir, f'CPP_{i}.dot')
        golden_dot_file = os.path.join(golden_dir, f'CPP_{i}.dot')

        if os.path.exists(test_dot_file) and os.path.exists(golden_dot_file):
            try:
                test_graph = load_graph_from_dot(test_dot_file)
                golden_graph = load_graph_from_dot(golden_dot_file)
                
                comparison_result, incorrectness_score = compare_graphs(test_graph, golden_graph)
                results.append((f'CPP_{i}.dot', f'CPP_{i}.dot', comparison_result, incorrectness_score))
            except Exception as e:
                print(f"Error processing pair CPP_{i}.dot: {e}")
                continue
        else:
            results.append((f'CPP_{i}.dot', f'CPP_{i}.dot', 'File not found', 'N/A'))
    
    # Write results to CSV
    with open(output_csv, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(['Test File', 'Golden File', 'Comparison Result', 'Incorrectness Score'])
        writer.writerows(results)

    print(f"Comparison results have been saved to {output_csv}.")

if __name__ == "__main__":
    test_dir = './'  # Directory containing your test DOT files
    golden_dir = '/home/anonymous/LLMs-in-IR/processed_data/Human_x_164_O3/organized dot/'  # Directory containing your golden DOT files
    output_csv = './comparison_results.csv'  # Output CSV file path
    
    process_all_dot_files(test_dir, golden_dir, output_csv)

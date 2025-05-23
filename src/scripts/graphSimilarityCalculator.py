import networkx as nx
import pydot
from networkx.drawing.nx_pydot import read_dot

def load_graph_from_dot(file_path):
    # Load the graph from a DOT file
    try:
        return read_dot(file_path)
    except Exception as e:
        print(f"An error occurred while reading the DOT file: {e}")
        return None

def calculate_graph_edit_distance(graph1, graph2):
    # Calculate the graph edit distance between two graphs
    try:
        return nx.graph_edit_distance(graph1, graph2)
    except Exception as e:
        print(f"An error occurred while calculating the graph edit distance: {e}")
        return None

def main(dot_file1, dot_file2):
    # Load graphs from DOT files
    graph1 = load_graph_from_dot(dot_file1)
    graph2 = load_graph_from_dot(dot_file2)
    
    if graph1 is None or graph2 is None:
        print("Error in loading graphs.")
        return
    
    # Calculate similarity (graph edit distance)
    ged = calculate_graph_edit_distance(graph1, graph2)
    
    if ged is not None:
        print(f"Graph Edit Distance between the graphs: {ged}")
    else:
        print("Error in calculating the graph edit distance.")

# Paths to your DOT files
dot_file1 = "../../processed_data/CFG/counting_sort2/counting_sort2_.main.dot"
dot_file2 = "../../processed_data/CFG_LLM/counting_sort2/ConstructtheArray_LLMs_cfg.dot"

# Run the main function
main(dot_file1, dot_file2)

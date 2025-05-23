import os
import pydot
import pandas as pd
import networkx as nx

# Function to load a DOT file using pydot and convert it to a networkx graph
def load_dot_with_pydot(dot_file_path):
    graphs = pydot.graph_from_dot_file(dot_file_path)
    if isinstance(graphs, list):
        graph = graphs[0]
    else:
        graph = graphs
    nx_graph = nx.nx_pydot.from_pydot(graph)
    if nx_graph.is_multigraph():
        nx_graph = nx.Graph(nx_graph)  # Convert to simple graph
    return nx_graph

# Function to analyze graph features
def analyze_graph_features(dot_file_path):
    graph = load_dot_with_pydot(dot_file_path)
    features = {
        'nodes': graph.number_of_nodes(),
        'edges': graph.number_of_edges(),
        'density': nx.density(graph),
        'avg_clustering': nx.average_clustering(graph),
        'degree_centrality': sum(nx.degree_centrality(graph).values()) / len(graph),
        'connected_components': nx.number_connected_components(graph)
    }
    return features

# Function to summarize features of graphs in a list
def summarize_graphs_in_list(file_list, graph_dir):
    summaries = []
    
    for file_name in file_list:
        dot_file_path = os.path.join(graph_dir, file_name)
        if os.path.exists(dot_file_path):
            features = analyze_graph_features(dot_file_path)
            features['file_name'] = file_name
            summaries.append(features)
    
    return pd.DataFrame(summaries)

# Function to save lists and summarize graph features
def save_summarize_graphs(category, filename_base, graph_dir, gpt4o_files, metallama_files, gemma27b_files):
    section_summaries = {}

    def save_list_and_summarize(file_set, section_name):
        file_list = list(file_set)
        with open(f"{filename_base}_{section_name}.txt", 'w') as f:
            f.write("\n".join(file_list))
        
        if file_list:
            summary_df = summarize_graphs_in_list(file_list, graph_dir)
            summary_df.to_csv(f"{filename_base}_{section_name}_summary.csv", index=False)
            section_summaries[section_name] = summary_df

    save_list_and_summarize(gpt4o_files - metallama_files - gemma27b_files, 'GPT4o_only')
    save_list_and_summarize(metallama_files - gpt4o_files - gemma27b_files, 'MetaLlama_only')
    save_list_and_summarize(gemma27b_files - gpt4o_files - metallama_files, 'Gemma27b_only')
    save_list_and_summarize((gpt4o_files & metallama_files) - gemma27b_files, 'GPT4o_and_MetaLlama')
    save_list_and_summarize((gpt4o_files & gemma27b_files) - metallama_files, 'GPT4o_and_Gemma27b')
    save_list_and_summarize((metallama_files & gemma27b_files) - gpt4o_files, 'MetaLlama_and_Gemma27b')
    save_list_and_summarize(gpt4o_files & metallama_files & gemma27b_files, 'all_three')
    
    return section_summaries

# Directory containing the dot files
graph_directory = '/home/anonymous/LLMs-in-IR/processed_data/Human_x_164_O3/organized dot/'

# Load the CSV files
gpt4o_file = './CFG_completion_analysis_results_GPT4o.csv'
metallama_file = './CFG_completion_analysis_results_MetaLlama.csv'
gemma27b_file = './CFG_completion_analysis_results_Gemma27b.csv'

gpt4o_df = pd.read_csv(gpt4o_file)
metallama_df = pd.read_csv(metallama_file)
gemma27b_df = pd.read_csv(gemma27b_file)

# Summarize and save graph features for each category
summaries_wrong = save_summarize_graphs('Wrong', 'summary_wrong', graph_directory,
                                        set(gpt4o_df[gpt4o_df['category'] == 'Wrong']['file_name']),
                                        set(metallama_df[metallama_df['category'] == 'Wrong']['file_name']),
                                        set(gemma27b_df[gemma27b_df['category'] == 'Wrong']['file_name']))

summaries_overall = save_summarize_graphs('Overall Completed', 'summary_overall_completed', graph_directory,
                                          set(gpt4o_df[gpt4o_df['category'] == 'Overall Completed']['file_name']),
                                          set(metallama_df[metallama_df['category'] == 'Overall Completed']['file_name']),
                                          set(gemma27b_df[gemma27b_df['category'] == 'Overall Completed']['file_name']))

summaries_loop = save_summarize_graphs('Loop Completed', 'summary_loop_completed', graph_directory,
                                       set(gpt4o_df[gpt4o_df['category'] == 'Loop Completed']['file_name']),
                                       set(metallama_df[metallama_df['category'] == 'Loop Completed']['file_name']),
                                       set(gemma27b_df[gemma27b_df['category'] == 'Loop Completed']['file_name']))

print("File lists and graph summaries have been generated and saved.")

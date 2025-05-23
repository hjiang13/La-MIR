"""
This script analyzes the Control Flow Graph (CFG) properties of DOT files corresponding to CPP files that have passed in different models (GPT4o, Gemma, Meta_Llama). The CPP files are categorized into seven sections based on their unique and shared occurrences across the models. For each section, the script computes various graph properties (such as the number of nodes, edges, average degree, density, and connectivity) to identify potential commonalities within each section.

The script works as follows:
1. Load the pass lists from three different models (GPT4o, Gemma, Meta_Llama) based on their respective summary CSV files.
2. Categorize the CPP files into seven sections (unique to each model, shared between two models, and shared across all three).
3. For each CPP file in each section, load the corresponding DOT file, parse it as a graph, and calculate various properties.
4. Handle directed graphs by checking their strong and weak connectivity, as appropriate.
5. Output the graph properties for each section into separate CSV files to facilitate further analysis of common characteristics within each group of CPP files.

This analysis can help in understanding whether there are shared structural patterns in the CFGs that could explain why certain files pass in one or more models.
"""

import pandas as pd
import networkx as nx
import os

# Load the CSV files
gpt4o_data = pd.read_csv('GPT4o.summary.csv')
gemma_data = pd.read_csv('Gemma.summary.csv')
meta_llama_data = pd.read_csv('Meta_Llama.summary.csv')

# Filter for Result = Pass
gpt4o_pass = set(gpt4o_data[gpt4o_data['Result'] == 'pass']['CPP_number'])
gemma_pass = set(gemma_data[gemma_data['Result'] == 'pass']['CPP_number'])
meta_llama_pass = set(meta_llama_data[meta_llama_data['Result'] == 'pass']['CPP_number'])

# Define the sections
sections = {
    '100': gpt4o_pass - gemma_pass - meta_llama_pass,  # Unique to GPT4o
    '010': gemma_pass - gpt4o_pass - meta_llama_pass,  # Unique to Gemma
    '001': meta_llama_pass - gpt4o_pass - gemma_pass,  # Unique to Meta_Llama
    '110': (gpt4o_pass & gemma_pass) - meta_llama_pass,  # Intersection of GPT4o and Gemma
    '011': (gemma_pass & meta_llama_pass) - gpt4o_pass,  # Intersection of Gemma and Meta_Llama
    '101': (gpt4o_pass & meta_llama_pass) - gemma_pass,  # Intersection of GPT4o and Meta_Llama
    '111': gpt4o_pass & gemma_pass & meta_llama_pass   # Intersection of all three
}

# Define the base path for the DOT files
dot_file_base_path = '/home/anonymous/LLMs-in-IR/processed_data/Human_x_164_O3/organized dot/'

# Define a function to parse a DOT file and calculate graph properties
def calculate_graph_properties(dot_file):
    G = nx.drawing.nx_pydot.read_dot(dot_file)
    
    if nx.is_directed(G):
        connectivity = nx.is_strongly_connected(G)
        num_scc = nx.number_strongly_connected_components(G)
        num_wcc = nx.number_weakly_connected_components(G)
    else:
        connectivity = nx.is_connected(G)
        num_scc = 'N/A'
        num_wcc = 'N/A'
    
    properties = {
        'num_nodes': G.number_of_nodes(),
        'num_edges': G.number_of_edges(),
        'avg_degree': sum(dict(G.degree()).values()) / float(G.number_of_nodes()),
        'density': nx.density(G),
        'is_connected': connectivity,
        'num_strongly_connected_components': num_scc,
        'num_weakly_connected_components': num_wcc
    }
    return properties

# Loop through each section, calculate graph properties, and save results to CSV
output_base_path = './graph_properties_output/'
os.makedirs(output_base_path, exist_ok=True)

for section, cpp_files in sections.items():
    section_properties = []
    for cpp_file in cpp_files:
        dot_file = os.path.join(dot_file_base_path, f'{cpp_file}.dot')
        if os.path.exists(dot_file):
            properties = calculate_graph_properties(dot_file)
            properties['CPP_number'] = cpp_file
            section_properties.append(properties)
        else:
            print(f"Warning: DOT file for {cpp_file} not found at {dot_file}.")
    
    # Convert to DataFrame and save to CSV
    df = pd.DataFrame(section_properties)
    output_file = os.path.join(output_base_path, f'section_{section}.csv')
    df.to_csv(output_file, index=False)
    print(f"Section {section} properties saved to {output_file}")


import pandas as pd
import matplotlib.pyplot as plt
from matplotlib_venn import venn3

# Load the CSV files
gpt4o_file = 'CFG_completion_analysis_results_GPT4o.csv'
metallama_file = 'CFG_completion_analysis_results_MetaLlama.csv'
gemma27b_file = 'CFG_completion_analysis_results_Gemma27b.csv'

gpt4o_df = pd.read_csv(gpt4o_file)
metallama_df = pd.read_csv(metallama_file)
gemma27b_df = pd.read_csv(gemma27b_file)

# Function to generate Venn diagram for a specific category
def draw_venn(category, filename):
    gpt4o_files = set(gpt4o_df[gpt4o_df['category'] == category]['file_name'])
    metallama_files = set(metallama_df[metallama_df['category'] == category]['file_name'])
    gemma27b_files = set(gemma27b_df[gemma27b_df['category'] == category]['file_name'])
    
    plt.figure(figsize=(8, 8))
    venn3([gpt4o_files, metallama_files, gemma27b_files],
          ('GPT-4o', 'MetaLlama', 'Gemma27b'))
    plt.title(f"Venn Diagram of {category} Category")
    plt.savefig(filename)
    plt.close()

# Draw and save Venn diagrams for each category
draw_venn('Wrong', 'venn_wrong.png')
draw_venn('Overall Completed', 'venn_overall_completed.png')
draw_venn('Loop Completed', 'venn_loop_completed.png')

print("Venn diagrams have been generated and saved as PNG files.")

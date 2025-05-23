from matplotlib_venn import venn3
import matplotlib.pyplot as plt

import pandas as pd

# Load the CSV file
file_path = './decompilationResult_O3.csv'
data = pd.read_csv(file_path)

# Define failure states
failure_terms = ["Execution Failed"]

# Create sets for each model where the execution failed
set_gpt4o = set(data[data['GPT4o'].isin(failure_terms)]['Number'])
set_gpt3_5 = set(data[data['GPT3.5'].isin(failure_terms)]['Number'])
set_metaLlama = set(data[data['Meta-Llama'].isin(failure_terms)]['Number'])
set_gemma27b = set(data[data['Gemma27b'].isin(failure_terms)]['Number'])

# Plot the Venn diagram
plt.figure(figsize=(8, 8))
venn = venn3([set_gpt4o, set_gpt3_5, set_metaLlama, set_gemma27b],
             ('GPT4o', 'GPT3.5', 'Meta-Llama', 'Gemma27b'))

plt.title('Venn Diagram of "Execution Failed" Results')
plt.show()

# Save the plot as an image file with vertical separation
output_plot_with_vertical_separation_path = "venn_execution_failed.png"
plt.tight_layout()
plt.savefig(output_plot_with_vertical_separation_path, dpi=1200)
plt.close()
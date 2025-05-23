import pandas as pd
import matplotlib.pyplot as plt
from matplotlib_venn import venn3

# Load the CSV file
csv_file = './rate_results_GPT4o.csv'  # Update with your CSV file path if needed
df = pd.read_csv(csv_file)

# Set the tolerance for completeness rates close to 1
tolerance = 0.05

# Find the files for each of the three conditions
overall_completeness_files = set(df[(df['overall_nodes_rate'] >= (1 - tolerance)) & (df['overall_nodes_rate'] <= (1 + tolerance))]['file_name'])
loop_completeness_files = set(df[(df['loop_nodes_rate'] >= (1 - tolerance)) & (df['loop_nodes_rate'] <= (1 + tolerance))]['file_name'])
branch_completeness_files = set(df[(df['branch_nodes_rate'] >= (1 - tolerance)) & (df['branch_nodes_rate'] <= (1 + tolerance))]['file_name'])

# Print the file names for each condition
print("Overall Completeness Rate (1 ± 0.05):")
print(overall_completeness_files)
print("\nLoop Completeness Rate (1 ± 0.05):")
print(loop_completeness_files)
print("\nConditional Branch Completeness Rate (1 ± 0.05):")
print(branch_completeness_files)

# Draw the Venn diagram
plt.figure(figsize=(8, 8))
venn3([overall_completeness_files, loop_completeness_files, branch_completeness_files],
      ('Overall Completeness', 'Loop Completeness', 'Conditional Branch Completeness'))

# Show the plot with title
plt.title("Venn Diagram of Completeness Rates from GPT4o")
plt.show()

# Save the plot as an image file with vertical separation
output_plot_with_vertical_separation_path = "venn_rate_results_GPT4o.png"
plt.tight_layout()
plt.savefig(output_plot_with_vertical_separation_path, dpi=1200)
plt.close()
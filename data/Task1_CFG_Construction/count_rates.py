import pandas as pd

# Load the CSV file
csv_file = 'rate_results_MetaLlama.csv'  # Update with your actual file path
df = pd.read_csv(csv_file)

# Filter the files with overall_nodes_rate in the range 0.9-1.1
filtered_df = df[(df['overall_nodes_rate'] >= 0.8) & (df['overall_nodes_rate'] <= 1.2)]

# Count the number of files that meet the criteria
num_files_in_range = len(filtered_df)

print(f"Number of DOT files with overall_nodes_rate in range 0.9-1.1: {num_files_in_range}")

import pandas as pd

# Load the test and golden result CSV files
test_csv = 'CFGResult_MetaLlama.csv'  # Path to your test CSV file
golden_csv = 'CFGResult_O3.csv'    # Path to your golden CSV file

# Load the CSV files into DataFrames
test_df = pd.read_csv(test_csv)
golden_df = pd.read_csv(golden_csv)

# Merge the DataFrames on the file_name column
merged_df = pd.merge(test_df, golden_df, on='file_name', suffixes=('_test', '_golden'))

# Define a function to calculate the rate, handling division by zero
def calculate_rate(test_value, golden_value):
    if golden_value == 0:
        return 'NA'
    else:
        return test_value / golden_value

# Apply the function to each relevant column
rate_columns = ['overall_nodes', 'overall_edges', 'loop_nodes', 'loop_edges', 'branch_nodes', 'branch_edges']
for column in rate_columns:
    merged_df[f'{column}_rate'] = merged_df.apply(lambda row: calculate_rate(row[f'{column}_test'], row[f'{column}_golden']), axis=1)

# Select the columns to keep in the output
output_columns = ['file_name'] + [f'{column}_rate' for column in rate_columns]

# Add the overall_nodes from the golden results as the last column
output_columns.append('overall_nodes_golden')

# Create the output DataFrame with the calculated rates and overall_nodes_golden
output_df = merged_df[output_columns]

# Save the output to a new CSV file
output_csv = 'rate_results_MetaLlama.csv'  # Desired output file path
output_df.to_csv(output_csv, index=False)

print(f"Rate calculation completed and results saved to {output_csv}")

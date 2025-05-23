import pandas as pd

# Load the test and golden result CSV files
test_csv = 'CFGResult_deepseek.csv'  # Replace with your test CSV file path
golden_csv = 'CFGResult_O3.csv'  # Replace with your golden CSV file path

# Load the CSV files into DataFrames
test_df = pd.read_csv(test_csv)
golden_df = pd.read_csv(golden_csv)

# Merge the DataFrames on the file_name column
merged_df = pd.merge(test_df, golden_df, on='file_name', suffixes=('_test', '_golden'))

# Function to categorize each dot file based on the rules provided
def categorize_file(row):
    overall_nodes_diff = abs(row['overall_nodes_test'] - row['overall_nodes_golden'])
    overall_edges_diff = abs(row['overall_edges_test'] - row['overall_edges_golden'])
    loop_edges_same = row['loop_edges_test'] == row['loop_edges_golden']
    branch_edges_same = row['branch_edges_test'] == row['branch_edges_golden']

    if overall_nodes_diff < 2 and overall_edges_diff < 2:
        return 'Overall Completed'
    elif overall_nodes_diff < 2:
        if loop_edges_same:
            return 'Loop Completed'
        elif branch_edges_same:
            return 'Branch Completed'
    return 'Wrong'

# Apply the categorization function to each row
merged_df['category'] = merged_df.apply(categorize_file, axis=1)

# Count the number of files in each category
category_counts = merged_df['category'].value_counts()

# Save the output to a new CSV file
output_csv = 'CFG_completion_analysis_results_deepseek.csv'  # Desired output file path
merged_df.to_csv(output_csv, index=False)

category_counts, output_csv

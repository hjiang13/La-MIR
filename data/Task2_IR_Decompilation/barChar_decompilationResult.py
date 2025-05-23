import pandas as pd
import matplotlib.pyplot as plt

import seaborn as sns
# Set the overall style
#sns.set(style="whitegrid")

# Use a generic serif font if Times New Roman is not found
plt.rcParams['font.family'] = 'serif'
plt.rcParams['font.serif'] = ['Times New Roman', 'Liberation Serif', 'serif']

# Load the merged CSV file (assuming it's already in the environment)
df_sorted_loc = pd.read_csv('decompilationResult_O3.csv')

# Analyzing the number of occurrences of each status category
status_columns = ['GPT4o', 'GPT3.5', 'Gemma27b', 'Meta-Llama']

# Mapping status types to a list of expected values
status_mapping = {
    'Passed': 'Passed',
    'Execution Failed': 'Execution Failed',
    'Compilation Failed': 'Compilation Failed',
    'Decompilation Failed': 'Decompilation Failed'
}

# Initialize a dictionary to count occurrences
status_counts = {status: {source: 0 for source in status_columns} for status in status_mapping.values()}

# Counting the occurrences of each status type for each source
for source in status_columns:
    counts = df_sorted_loc[source].value_counts()
    for status, count in counts.items():
        # Map the status to the correct category
        mapped_status = status_mapping.get(status, status)
        status_counts[mapped_status][source] = count

# Creating a DataFrame for easier plotting
status_counts_df = pd.DataFrame(status_counts)

# Plotting the grouped bar chart
ax = status_counts_df.T.plot(kind='bar', figsize=(6, 4), color=['#FF9999', '#66B2FF', '#99FF99', '#FFCC99'])

# Adding labels and title
#plt.xlabel('Status Type')
#plt.ylabel('Count')
plt.title('The decompilation results across LLMs', fontsize=14)
plt.ylim(0, 140)
plt.legend(title='LLMs', loc='upper right', fontsize=10)
plt.xticks(rotation=15, fontsize=10)
plt.yticks(fontsize=10)

# Save the plot as an image file
output_bar_chart_path = "status_type_count_grouped_bar_chart.png"
plt.tight_layout()
plt.savefig(output_bar_chart_path, dpi=1200)
plt.close()

output_bar_chart_path

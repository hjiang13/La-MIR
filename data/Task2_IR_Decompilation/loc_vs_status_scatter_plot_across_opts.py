import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Use a generic serif font if Times New Roman is not found
plt.rcParams['font.family'] = 'serif'
plt.rcParams['font.serif'] = ['Times New Roman', 'Liberation Serif', 'serif']

# Load the merged CSV file
df_sorted_loc = pd.read_csv('Decompliation_GPT4o_O123_LOC.csv')

# Analyzing the number of occurrences of each status category
status_columns = ['opt -O0', 'opt -O1', 'opt -O2', 'opt -O3']

# Sorting the dataframe by LOC from small to large
df_sorted_loc = df_sorted_loc.sort_values('LOC').reset_index(drop=True)

# Mapping status types to numerical values for y-axis
status_mapping = {
    'Passed': 1,
    'Execution Failed': 2,
    'Compilation Failed': 3,
    'Decompilation Failed': 4
}

# Creating a long-form DataFrame for easier plotting
long_form_data = pd.melt(df_sorted_loc, id_vars=['LOC'], value_vars=status_columns, var_name='Source', value_name='Status')

# Mapping the statuses to numerical values
long_form_data['Status_mapped'] = long_form_data['Status'].map(status_mapping)

# Distribute the points vertically within each status category
source_offset = {
    'opt -O0': 0.3,
    'opt -O1': 0.1,
    'opt -O2': -0.1,
    'opt -O3': -0.3
}
long_form_data['Status_offset'] = long_form_data.apply(lambda row: row['Status_mapped'] + source_offset[row['Source']], axis=1)

# Mapping each source to a specific color
color_mapping = {
    'opt -O3': '#FF9999',
    'opt -O2': '#66B2FF',
    'opt -O1': '#99FF99',
    'opt -O0': '#FFCC99'
}

# Creating the scatter plot
plt.figure(figsize=(6, 4))

# Plot each status with corresponding color and offset y-axis
for source in status_columns:
    subset = long_form_data[long_form_data['Source'] == source]
    plt.scatter(subset['LOC'], subset['Status_offset'], color=color_mapping[source], label=source, alpha=0.6)

# Adding labels and title
plt.xlabel('LOC of IR code', fontsize=10)
#plt.ylabel('Status Type')
plt.yticks(ticks=[1, 2, 3, 4], labels=['Passed', 'Execution Failed', 'Compilation Failed', 'Decompilation Failed'], rotation=75, fontsize=10)
plt.title('Scatter Plot of decompilation results from GPT-4o vs LOC of IR across opts', fontsize=12)
plt.legend(title='LLMs', fontsize=10)

# Save the plot as an image file with vertical separation
output_plot_with_vertical_separation_path = "loc_vs_status_scatter_plot_with_vertical_separation_across_opt.png"
plt.tight_layout()
plt.savefig(output_plot_with_vertical_separation_path, dpi=1200)
plt.close()

print(f"Scatter plot with vertical separation saved to {output_plot_with_vertical_separation_path}")

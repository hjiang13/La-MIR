import pandas as pd
import matplotlib.pyplot as plt

# Load the CSV file
csv_file = 'rate_results_GPT4o.csv'  # Replace with your CSV file path
df = pd.read_csv(csv_file)

# Filter out rows where overall_nodes_golden is NA or 0
df = df[df['overall_nodes_golden'] > 0]

# Sort data by overall_nodes_golden
df = df.sort_values(by='overall_nodes_golden')

# Convert 'NA' values to None for plotting
df.replace('NA', None, inplace=True)

# Convert numeric columns to float
df['overall_nodes_rate'] = pd.to_numeric(df['overall_nodes_rate'], errors='coerce')
df['overall_edges_rate'] = pd.to_numeric(df['overall_edges_rate'], errors='coerce')

# Filter the data to focus on results within the range 0 to 2 for both rates
filtered_df = df[
    (df['overall_nodes_rate'].between(0, 2)) &
    (df['overall_edges_rate'].between(0, 2))
]

# Create the scatter plot
plt.figure(figsize=(10, 6))
plt.scatter(filtered_df['overall_nodes_golden'], filtered_df['overall_nodes_rate'], label='Overall Nodes Rate', color='blue')
plt.scatter(filtered_df['overall_nodes_golden'], filtered_df['overall_edges_rate'], label='Overall Edges Rate', color='red')

# Add labels and title
plt.xlabel('Overall Nodes (Golden)')
plt.ylabel('Rate')
plt.title('Scatter Plot of Overall Nodes and Edges Rate vs. Golden Nodes')
plt.legend()

# Show the plot
plt.grid(True)
plt.ylim(0, 2)  # Set the y-axis limits to focus on the range from 0 to 2
plt.show()



# Save the plot as an image file with vertical separation
output_plot_with_vertical_separation_path = "rate_results_GPT4o.png"
plt.tight_layout()
plt.savefig(output_plot_with_vertical_separation_path, dpi=1200)
plt.close()
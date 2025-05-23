import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.patches as patches
import os

# List of CSV files
csv_files = ['section_001.csv', 'section_010.csv', 'section_011.csv', 
             'section_100.csv', 'section_101.csv', 'section_110.csv', 'section_111.csv']

# Directory containing the CSV files
directory = '/home/anonymous/LLMs-in-IR/Data/execution task/graph_properties_output'

# Dictionary to store density data
density_data = {}

# Load and filter the data from each CSV
for csv_file in csv_files:
    file_path = os.path.join(directory, csv_file)
    df = pd.read_csv(file_path)
    df_filtered = df[df['density'] > 0]  # Exclude rows where density is 0
    density_data[csv_file] = df_filtered['density'].values

# Set up the plot
fig, ax = plt.subplots(figsize=(10, 6))

# Colors for different sections
colors = ['#74AA9C', '#EA4335', '#0081FB', '#FFA500', '#64B0D3', '#95A7E4', '#89C0B9']
labels = [f'Section {csv_file.split(".")[0]}' for csv_file in csv_files]

x = np.arange(len(labels))  # Label locations
width = 0.35  # Width of the rectangles

# Plot each section's density
for i, (label, color) in enumerate(zip(labels, colors)):
    densities = density_data[csv_files[i]]
    avg_density = np.mean(densities)
    min_density = np.min(densities)
    max_density = np.max(densities)
    
    # Draw small rectangles
    rect = patches.Rectangle((x[i] - width/2, avg_density - 0.01), width/4, 0.02, color=color, label=label)
    ax.add_patch(rect)
    ax.errorbar(x[i] - width/2, avg_density, yerr=[[avg_density - min_density], [max_density - avg_density]], 
                fmt='none', capsize=5, color=color)
    
    # Label the rectangle with the average density
    ax.annotate(f'{avg_density:.3f}', xy=(x[i] - width/2, avg_density), xytext=(0, 3),
                textcoords="offset points", ha='center', va='bottom')

# Set labels and title
ax.set_xlabel('CSV Sections')
ax.set_ylabel('Density')
ax.set_title('Density Distribution Across CSV Sections')
ax.set_xticks(x)
ax.set_xticklabels(labels)
ax.legend(loc='upper right')

# Save and show the plot
plt.tight_layout()
plt.savefig("density_distribution_across_sections.png")
plt.show()

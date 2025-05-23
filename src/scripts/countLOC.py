import os
import csv

# Directory containing the folders
base_dir = "../../processed_data/Human_x_164_O3"

# List to store the number and corresponding LOC
data = []

# Iterate over the range of folder numbers
for i in range(164):
    # Construct the file path
    file_path = os.path.join(base_dir, f"CPP_{i}", f"CPP_{i}.bc")
    
    # Check if the file exists
    if os.path.isfile(file_path):
        # Count the lines in the file
        with open(file_path, 'r') as file:
            loc = sum(1 for _ in file)
        
        # Append the result to the data list
        data.append([i, loc])
    else:
        # Handle the case where the file does not exist
        data.append([i, 0])  # Assuming 0 LOC for non-existent files

# Output CSV file path
output_csv = "../../Data/output_LOC_O3.csv"

# Write the results to a CSV file
with open(output_csv, 'w', newline='') as csvfile:
    writer = csv.writer(csvfile)
    writer.writerow(['number', 'LOC'])
    writer.writerows(data)

print(f"Results have been written to {output_csv}")

import os
import csv

# Paths
execution_failed_csv = 'execution_failed_summary.csv'  # Replace with your CSV file path
base_directory = '/home/anonymous/LLMs-in-IR/Human_xBenchmarks_164'  # Replace with the path to the folder containing folders like CPP_134, CPP_78, etc.

# Read the failed execution data from CSV
failed_files = {}
with open(execution_failed_csv, 'r') as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        file_name = row['File Name']
        failed_files[file_name] = row['Compilation Result']

# Check if the corresponding folders contain the correct .cpp files
for cpp_file in failed_files:
    folder_name = os.path.join(base_directory, cpp_file.replace('.cpp', ''))
    cpp_file_path = os.path.join(folder_name, cpp_file)
    if os.path.exists(cpp_file_path):
        failed_files[cpp_file] = 'Correct'

# Write the updated CSV file
updated_csv_filename = 'updated_execution_failed_summary.csv'
with open(updated_csv_filename, 'w', newline='') as csvfile:
    csv_writer = csv.writer(csvfile)
    csv_writer.writerow(['File Name', 'Compilation Result', 'Errors'])
    for file_name, result in failed_files.items():
        csv_writer.writerow([file_name, result, ''])

print(f"Updated summary saved to {updated_csv_filename}")

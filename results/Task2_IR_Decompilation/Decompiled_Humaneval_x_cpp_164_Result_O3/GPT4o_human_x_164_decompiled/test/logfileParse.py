import re
import csv

# Initialize variables
log_filename = 'results.log'  # Replace with your log file path
output_csv_filename = 'error_summary.csv'

# Regex patterns to capture information
file_pattern = re.compile(r'^(CPP_\d+\.cpp): (\w+ \w+)$')
error_pattern = re.compile(r'error: (.+)$')

# Initialize a list to hold the summarized data
summary_data = []

# Read the log file and parse it
with open(log_filename, 'r') as log_file:
    current_file = None
    current_result = None
    errors = []

    for line in log_file:
        file_match = file_pattern.match(line)
        if file_match:
            if current_file:
                # Save the previous file's summary before starting a new one
                summary_data.append([current_file, current_result, '; '.join(errors)])
            # Start a new file's data
            current_file = file_match.group(1)
            current_result = file_match.group(2)
            errors = []  # Reset the errors list for the new file
        else:
            error_match = error_pattern.search(line)
            if error_match:
                errors.append(error_match.group(1))

    # Append the last file's summary
    if current_file:
        summary_data.append([current_file, current_result, '; '.join(errors)])

# Filter out "Execution Failed" entries
execution_failed_data = [entry for entry in summary_data if entry[1] == 'Execution Failed']

# Write the summary data to a CSV file
with open(output_csv_filename, 'w', newline='') as csvfile:
    csv_writer = csv.writer(csvfile)
    csv_writer.writerow(['File Name', 'Compilation Result', 'Errors'])
    csv_writer.writerows(summary_data)

# Also save the "Execution Failed" data to a separate CSV file
execution_failed_csv_filename = 'execution_failed_summary.csv'
with open(execution_failed_csv_filename, 'w', newline='') as csvfile:
    csv_writer = csv.writer(csvfile)
    csv_writer.writerow(['File Name', 'Compilation Result', 'Errors'])
    csv_writer.writerows(execution_failed_data)

print(f"Summary saved to {output_csv_filename}")
print(f"Execution Failed summary saved to {execution_failed_csv_filename}")

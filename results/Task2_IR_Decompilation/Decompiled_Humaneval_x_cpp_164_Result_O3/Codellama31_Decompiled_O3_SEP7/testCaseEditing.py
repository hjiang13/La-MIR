import os
import json

# Directory containing the .cpp files
cpp_dir = '.'
# Directory to save the modified .cpp files
output_dir = './test'
# Path to the jsonl file
jsonl_file_path = '../../../Human_xBenchmarks_164/humaneval.jsonl'

# Ensure the output directory exists
os.makedirs(output_dir, exist_ok=True)

# Load the test cases from the jsonl file
test_cases = {}
with open(jsonl_file_path, 'r') as jsonl_file:
    for line in jsonl_file:
        case = json.loads(line)
        task_id = case['task_id'].replace("/", "_")
        test_cases[task_id] = case['test']

# Initialize a counter for not completed files
not_completed_count = 0

# Function to keep only the content between the first and second "```"
def extract_code_block(lines):
    new_lines = []
    inside_block = False
    for line in lines:
        if "```" in line:
            if inside_block:  # End of the second block
                break
            else:  # Start of the first block
                inside_block = True
            continue  # Skip the line with "```"
        if inside_block:
            new_lines.append(line)
    return new_lines

# Process each .cpp file
for filename in os.listdir(cpp_dir):
    if filename.endswith('.cpp'):
        file_path = os.path.join(cpp_dir, filename)
        
        with open(file_path, 'r') as cpp_file:
            lines = cpp_file.readlines()

        # Check if the file contains "I am sorry"
        if any("I'm sorry" in line for line in lines):
            print(f"File {filename} is not completed.")
            not_completed_count += 1
            continue  # Skip processing this file since it's not completed

        # Extract content between the first and second "```"
        lines = extract_code_block(lines)

        # Get the task_id from the filename
        task_id = filename.split('.')[0]

        # Append the test case to the modified content
        if task_id in test_cases:
            lines.append("\n")
            lines.append(test_cases[task_id])

        # Write the modified content to a new file in the output directory
        output_file_path = os.path.join(output_dir, filename)
        with open(output_file_path, 'w') as output_file:
            output_file.writelines(lines)

# Output the number of not completed files
print(f"Number of files not completed: {not_completed_count}")
print("All other files have been processed and saved to the output directory.")

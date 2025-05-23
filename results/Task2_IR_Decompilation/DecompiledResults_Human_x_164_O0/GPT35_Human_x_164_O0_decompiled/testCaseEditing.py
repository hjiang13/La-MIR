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

# Process each .cpp file
for filename in os.listdir(cpp_dir):
    if filename.endswith('.cpp'):
        file_path = os.path.join(cpp_dir, filename)
        
        with open(file_path, 'r') as cpp_file:
            lines = cpp_file.readlines()

        # Remove the first and last lines
        if lines[0].strip() == "```cpp":
            lines = lines[1:]
        if lines[-1].strip() == "```":
            lines = lines[:-1]

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

print("All files have been processed and saved to the output directory.")

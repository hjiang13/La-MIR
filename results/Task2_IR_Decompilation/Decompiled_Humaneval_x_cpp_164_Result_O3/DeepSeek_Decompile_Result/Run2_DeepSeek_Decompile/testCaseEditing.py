import os
import json

# Directory containing the .cpp files
cpp_dir = '.'
# Directory to save the modified .cpp files
output_dir = './test'
# Path to the jsonl file
jsonl_file_path = '/home/hailong/LLMs-in-IR/Human_xBenchmarks_164/humaneval.jsonl'

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

        # Find positions of the ```cpp and ``` markers
        start_idx, end_idx = None, None
        for idx, line in enumerate(lines):
            if line.strip() == "```cpp":
                start_idx = idx
                break
        
        for idx, line in enumerate(lines):
            if line.strip() == "```" and idx > (start_idx if start_idx is not None else -1):
                end_idx = idx
                break

        # Extract lines between markers
        if start_idx is not None and end_idx is not None:
            lines = lines[start_idx + 1:end_idx]
        else:
            # Handle cases where markers are not found
            print(f"Markers not found properly in file: {filename}")
            continue

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

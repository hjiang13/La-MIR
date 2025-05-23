import os
import json

# Directory containing the folders
base_dir = '.'
# Directory to save the modified .cpp files
output_dir = './test'
# Path to the jsonl file
jsonl_file_path = './humaneval.jsonl'

# Ensure the output directory exists
os.makedirs(output_dir, exist_ok=True)

# Load the test cases from the jsonl file
test_cases = {}
with open(jsonl_file_path, 'r') as jsonl_file:
    for line in jsonl_file:
        case = json.loads(line)
        task_id = case['task_id'].replace("/", "_")
        test_cases[task_id] = case['test']

# Verify test cases are loaded
print(f"Loaded {len(test_cases)} test cases.")

# Process each folder
for folder_name in os.listdir(base_dir):
    if folder_name.startswith('CPP_'):
        folder_path = os.path.join(base_dir, folder_name)
        if os.path.isdir(folder_path):
            cpp_file_name = f"{folder_name}.cpp"
            cpp_file_path = os.path.join(folder_path, cpp_file_name)
            
            if os.path.exists(cpp_file_path):
                with open(cpp_file_path, 'r') as cpp_file:
                    lines = cpp_file.readlines()

                # Get the task_id from the folder name
                task_id = folder_name.replace("CPP_", "CPP/")
                task_id = task_id.replace("/", "_")

                # Ensure test case exists for the task_id
                if task_id in test_cases:
                    print(f"Appending test case for {task_id} to {cpp_file_name}.")
                    
                    # Append the test case to the modified content
                    lines.append("\n")
                    lines.append(test_cases[task_id])

                    # Write the modified content to a new file in the output directory
                    output_file_path = os.path.join(output_dir, cpp_file_name)
                    with open(output_file_path, 'w') as output_file:
                        output_file.writelines(lines)

                    print(f"Processed {cpp_file_name} successfully.")
                else:
                    print(f"Test case not found for {task_id}. Skipping {cpp_file_name}.")
            else:
                print(f"{cpp_file_name} does not exist in {folder_path}.")

print("All files have been processed and saved to the output directory.")

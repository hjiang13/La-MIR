import os

def process_file(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()
    
    # Find the indices of the first "```c" and the last "```"
    start_code_block = None
    end_code_block = None
    
    for i, line in enumerate(lines):
        if line.strip() == "```c":
            start_code_block = i
        elif line.strip() == "```":
            end_code_block = i
    
    # Debug: print indices of the first "```c" and the last "```"
    print(f"Processing {file_path}")
    print(f"Start of code block at line: {start_code_block}")
    print(f"End of code block at line: {end_code_block}")

    # If we found both, we can process the lines
    if start_code_block is not None and end_code_block is not None and end_code_block > start_code_block:
        # Keep lines only between "```c" and the last "```"
        processed_lines = lines[start_code_block + 1:end_code_block]
    else:
        # If the format is not as expected, do not change the file
        print(f"File format unexpected for {file_path}, skipping processing.")
        processed_lines = lines

    # Debug: print number of processed lines
    print(f"Number of processed lines: {len(processed_lines)}")

    # Write the processed lines back to the file
    with open(file_path, 'w') as file:
        file.writelines(processed_lines)

def process_files_in_directory(directory_path):
    for root, dirs, files in os.walk(directory_path):
        for file_name in files:
            if file_name.endswith('.cpp'):  # Assuming your files have a .c extension
                file_path = os.path.join(root, file_name)
                process_file(file_path)

# Set the path to the directory containing your files
directory_path = '.'
process_files_in_directory(directory_path)

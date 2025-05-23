import os
import re

def extract_function_name(bc_file_path):
    """Extracts the function name from the .bc file."""
    with open(bc_file_path, 'r') as bc_file:
        for line in bc_file:
            if "define dso_local" in line:
                match = re.search(r'@(_Z[\w\d]+)', line)
                if match:
                    return match.group(1)
    return None

def process_dot_file(dot_file_path, output_dot_file_path):
    """Rewrites the .dot file with simplified node names and labels."""
    with open(dot_file_path, 'r') as dot_file:
        dot_content = dot_file.read()

    # Regex to find nodes and their labels
    node_pattern = re.compile(r'(Node[\w\d]+)\s\[.*label="\{(%\d+):.*?"\];')

    # Dictionary to store node renaming
    node_rename_map = {}

    # Replace nodes with the head of the basic block
    def replace_node(match):
        node_id = match.group(1)
        block_head = match.group(2).lstrip('%')
        new_node_name = f'block_{block_head}'
        new_label = f'Block_{block_head}'

        node_rename_map[node_id] = new_node_name  # Map old node id to new node name
        return f'{new_node_name} [label="{new_label}"];'

    # Replace nodes in the .dot content
    new_dot_content = node_pattern.sub(replace_node, dot_content)

    # Replace old node names with new names in the edges
    for old_node_name, new_node_name in node_rename_map.items():
        edge_pattern = re.compile(r'\b' + re.escape(old_node_name) + r'\b')
        new_dot_content = edge_pattern.sub(new_node_name, new_dot_content)

    # Write the new content to the output .dot file
    with open(output_dot_file_path, 'w') as output_dot_file:
        output_dot_file.write(new_dot_content)

def process_cpp_folders(base_dir, organized_dir):
    """Processes all CPP_number folders and rewrites the corresponding .dot files."""
    # Create the organized dot folder if it doesn't exist
    if not os.path.exists(organized_dir):
        os.makedirs(organized_dir)

    # Iterate through each CPP_number folder
    for folder_name in os.listdir(base_dir):
        folder_path = os.path.join(base_dir, folder_name)
        if os.path.isdir(folder_path) and folder_name.startswith('CPP_'):
            # Find the .bc file
            bc_file_path = None
            dot_files = []
            for file_name in os.listdir(folder_path):
                if file_name.endswith('.bc'):
                    bc_file_path = os.path.join(folder_path, file_name)
                elif file_name.endswith('.dot'):
                    dot_files.append(os.path.join(folder_path, file_name))
            
            if bc_file_path:
                # Extract the function name
                function_name = extract_function_name(bc_file_path)
                if function_name:
                    # Find the matching .dot file
                    for dot_file_path in dot_files:
                        with open(dot_file_path, 'r') as dot_file:
                            if function_name in dot_file.read():
                                # Process and rewrite the .dot file
                                output_dot_file_path = os.path.join(organized_dir, f'{folder_name}.dot')
                                process_dot_file(dot_file_path, output_dot_file_path)
                                print(f'Rewritten {output_dot_file_path}')
                                break

# Example usage:
base_dir = '.'  # Replace with the path to the directory containing CPP_number folders
organized_dir = os.path.join(base_dir, 'organized dot')  # Output directory for processed dot files

process_cpp_folders(base_dir, organized_dir)

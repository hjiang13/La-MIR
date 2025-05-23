import os
import re

# Base directory containing the folders
base_dir = './'

# Function to parse IR code and build a call graph
def build_call_graph(ir_code):
    function_definitions = {}
    all_functions = set()  # To keep track of all functions used (defined or called)

    function_def_pattern = re.compile(r'define .* @(\w+)\(')
    function_call_pattern = re.compile(r'call.*@([\w\.]+)\(')

    current_function = None

    for line in ir_code.splitlines():
        # Check for function definition
        match = function_def_pattern.search(line)
        if match:
            current_function = match.group(1)
            function_definitions[current_function] = []
            all_functions.add(current_function)

        # Check for function calls anywhere in the line
        if current_function:
            call_matches = function_call_pattern.findall(line)
            for called_function in call_matches:
                function_definitions[current_function].append(called_function)
                all_functions.add(called_function)

    return function_definitions, all_functions

# Function to generate DOT format string
def generate_dot(function_definitions, all_functions):
    dot_lines = []
    dot_lines.append('digraph CallGraph {')
    dot_lines.append('    // Nodes')

    # Add all function nodes
    for function in all_functions:
        dot_lines.append(f'    {function} [label="{function}"];')
    
    dot_lines.append('')
    dot_lines.append('    // Edges')

    # Add function call edges
    for caller, callees in function_definitions.items():
        for callee in callees:
            dot_lines.append(f'    {caller} -> {callee};')
    
    dot_lines.append('}')
    
    return '\n'.join(dot_lines)

# Loop through each folder and process the .bc file
for folder in os.listdir(base_dir):
    folder_path = os.path.join(base_dir, folder)
    
    if os.path.isdir(folder_path) and folder.startswith('CPP_'):
        bc_file = os.path.join(folder_path, f'{folder}.bc')

        if os.path.isfile(bc_file):
            # Assuming you can obtain the IR code from the .bc file
            # If you have a way to convert .bc to IR, do that here
            with open(bc_file, 'r') as file:
                ir_code = file.read()

            # Build the call graph from the IR code
            function_definitions, all_functions = build_call_graph(ir_code)

            # Generate DOT format string
            dot_content = generate_dot(function_definitions, all_functions)

            # Save the DOT format string to a .dot file
            output_dot_file = os.path.join(folder_path, f'{folder}_call_graph.dot')
            with open(output_dot_file, 'w') as f:
                f.write(dot_content)

        else:
            print(f'BC file not found in {folder}')

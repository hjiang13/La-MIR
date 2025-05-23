import os

# Directory containing the folders
base_dir = "../../processed_data/Human_x_164_O3"

# Initialize total counters
total_lines = 0
total_tokens = 0
total_functions = 0
total_basic_blocks = 0
total_loops = 0
# Iterate over the range of folder numbers
for i in range(164):
    # Construct the file path
    file_path = os.path.join(base_dir, f"CPP_{i}", f"CPP_{i}.bc")
    if os.path.isfile(file_path):
        try:
            with open(file_path, 'r', encoding='utf-8') as f:
                content = f.read()
                
                # Count lines by splitting into lines.
                lines = content.splitlines()
                line_count = len(lines)
                
                # Count tokens: splitting by any whitespace.
                tokens = content.split()
                token_count = len(tokens)
                
                # Count functions: count occurrences of "define"
                function_count = content.count("define")
                
                # Count basic blocks as the sum of occurrences of "press" and "define"
                basic_block_count = content.count("preds") + content.count("define")

                # Count loops: using "llvm.loop" as an indicator for a loop
                loop_count = content.count("llvm.loop !")
                                
                # Update totals
                total_lines += line_count
                total_tokens += token_count
                total_functions += function_count
                total_basic_blocks += basic_block_count
                total_loops += loop_count
                
                print(f"File: {file_path}")
                print(f"  Lines: {line_count}")
                print(f"  Tokens: {token_count}")
                print(f"  Functions (using 'define'): {function_count}")
                print(f"  Basic Blocks (preds + define): {basic_block_count}\n")
        except Exception as e:
            print(f"Could not process file {file_path}: {e}")
    else:
        print(f"File not found: {file_path}")

print("=== Overall Totals ===")
print(f"Total lines: {total_lines}")
print(f"Total tokens: {total_tokens}")
print(f"Total functions (using 'define'): {total_functions}")
print(f"Total basic blocks (press + define): {total_basic_blocks}")
print(f"Total Loops (llvm.loop): {total_loops}\n")
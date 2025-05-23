import os
import subprocess

# Directory containing the .cpp files
cpp_dir = './'
# Directory to save the executable files
bin_dir = './bin'
# Log file to record the results
log_file_path = './results.log'
# Timeout for compilation and execution in seconds
timeout_seconds = 10

# Ensure the binary directory exists
os.makedirs(bin_dir, exist_ok=True)

# Initialize counters
total_files = 0
compilation_failures = 0
execution_failures = 0
assertion_failures = 0

# List to store the results
results = []

# Prepare log file
with open(log_file_path, 'w') as log_file:
    log_file.write("Compilation and Execution Results\n")
    log_file.write("=================================\n\n")

# Process each .cpp file
for filename in os.listdir(cpp_dir):
    if filename.endswith('.cpp'):
        total_files += 1
        file_path = os.path.join(cpp_dir, filename)
        bin_file_path = os.path.join(bin_dir, filename.replace('.cpp', ''))

        # Compile the C++ file
        compile_command = f"g++ -o {bin_file_path} {file_path}"
        try:
            compile_result = subprocess.run(compile_command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=timeout_seconds)
        except subprocess.TimeoutExpired:
            compilation_failures += 1
            results.append(f"{filename} Compilation Timed Out")
            with open(log_file_path, 'a') as log_file:
                log_file.write(f"{filename}: Compilation Timed Out\n\n")
            continue

        if compile_result.returncode != 0:
            compilation_failures += 1
            results.append(f"{filename} Compilation Failed")
            with open(log_file_path, 'a') as log_file:
                log_file.write(f"{filename}: Compilation Failed\n")
                log_file.write(f"Error: {compile_result.stderr.decode('utf-8')}\n\n")
            continue

        # Run the executable
        execute_command = f"{bin_file_path}"
        try:
            execute_result = subprocess.run(execute_command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=timeout_seconds)
        except subprocess.TimeoutExpired:
            execution_failures += 1
            results.append(f"{filename} Execution Timed Out")
            with open(log_file_path, 'a') as log_file:
                log_file.write(f"{filename}: Execution Timed Out\n\n")
            continue

        if execute_result.returncode != 0:
            execution_failures += 1
            results.append(f"{filename} Execution Failed")
            with open(log_file_path, 'a') as log_file:
                log_file.write(f"{filename}: Execution Failed\n")
                log_file.write(f"Error: {execute_result.stderr.decode('utf-8')}\n\n")
            continue

        # Check for assertion failures in the output
        output = execute_result.stdout.decode('utf-8')
        if "Assertion" in output or execute_result.returncode != 0:
            assertion_failures += 1
            results.append(f"{filename} Assertion Failed")
            with open(log_file_path, 'a') as log_file:
                log_file.write(f"{filename}: Assertion Failed\n")
                log_file.write(f"Output: {output}\n\n")
        else:
            results.append(f"{filename} Passed")

# Summarize the results
with open(log_file_path, 'a') as log_file:
    log_file.write("Summary\n")
    log_file.write("=======\n")
    log_file.write(f"Total files processed: {total_files}\n")
    log_file.write(f"Compilation failures: {compilation_failures}\n")
    log_file.write(f"Execution failures: {execution_failures}\n")
    log_file.write(f"Assertion failures: {assertion_failures}\n\n")

    log_file.write("Detailed Results\n")
    log_file.write("===============\n")
    for result in results:
        log_file.write(result + "\n")

# Print summary of results
print(f"Processing complete. Results have been saved to {log_file_path}.")
print("Summary:")
print(f"Total files processed: {total_files}")
print(f"Compilation failures: {compilation_failures}")
print(f"Execution failures: {execution_failures}")
print(f"Assertion failures: {assertion_failures}\n")

print("Detailed Results:")
for result in results:
    print(result)

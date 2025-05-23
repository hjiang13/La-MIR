
import os
import subprocess

# Define paths
benchmarks_dir = "../../Human_xBenchmarks_164"
processed_data_dir = "../../processed_data/Human_x_164_O2"
scripts_dir = "."

# Function to compile and generate CFG
def process_benchmark(benchmark_path, output_dir, benchmark_name):
    # Compile the benchmark to LLVM IR
    clang_command = f"clang++ -O2 -emit-llvm {benchmark_path} -S -o {output_dir}/{benchmark_name}.bc"
    subprocess.run(clang_command, shell=True, check=True)

    # Generate the CFG dot file
    opt_command = f"opt -dot-cfg {output_dir}/{benchmark_name}.bc -disable-output"
    subprocess.run(opt_command, shell=True, check=True)

    # Move the dot files to the output directory and rename them to make them visible
    dot_files = [f for f in os.listdir(".") if f.endswith('.dot')]
    for dot_file in dot_files:
        new_name = f"{benchmark_name}_{dot_file}"
        new_path = os.path.join(output_dir, new_name)
        mv_command = f"mv {dot_file} {new_path}"
        subprocess.run(mv_command, shell=True, check=True)

# Traverse the Benchmarks directory
for root, dirs, files in os.walk(benchmarks_dir):
    for dir_name in dirs:
        benchmark_name = dir_name
        benchmark_path = os.path.join(root, dir_name, f"{benchmark_name}.cpp")
        output_dir = os.path.join(processed_data_dir, dir_name)

        # Ensure the output directory exists
        os.makedirs(output_dir, exist_ok=True)

        # Process the benchmark
        if os.path.isfile(benchmark_path):
            # Save the current working directory
            current_dir = os.getcwd()

            # Change to the scripts directory where dot files will be generated
            os.chdir(scripts_dir)
            process_benchmark(benchmark_path, output_dir, benchmark_name)

            # Change back to the original working directory
            os.chdir(current_dir)

print("Processing complete.")
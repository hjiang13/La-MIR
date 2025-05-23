import os
import pandas as pd

# Paths
cpp_folder = '/home/anonymous/LLMs-in-IR/Human_xBenchmarks_164/test'  # Replace with the path to your folder containing .cpp files
gpt4o_summary = './GPT4o.summary.csv'  # Replace with the actual path to your GPT4o summary CSV
gpt4_sc_summary = './GPT4_SC_summary.csv'  # Replace with the actual path to your GPT4_SC summary CSV

# Load the summary CSVs into DataFrames
gpt4o_df = pd.read_csv(gpt4o_summary)
gpt4_sc_df = pd.read_csv(gpt4_sc_summary)

# Initialize a list to store the results
cpp_data = []

# Iterate through the .cpp files in the folder
for filename in os.listdir(cpp_folder):
    if filename.endswith('.cpp'):
        # Extract the CPP_number from the filename (assuming the filename is like 'CPP_0.cpp')
        cpp_number = filename.replace('.cpp', '')
        
        # Read the content of the .cpp file
        with open(os.path.join(cpp_folder, filename), 'r') as file:
            cpp_code = file.read()
        
        # Get the corresponding 'pass', 'fail', or 'partial pass' for GPT4 and GPT4_SC
        gpt4o_label = gpt4o_df.loc[gpt4o_df['CPP_number'] == cpp_number, 'Result'].values[0]  # Adjust column name if necessary
        gpt4_sc_label = gpt4_sc_df.loc[gpt4_sc_df['CPP_number'] == cpp_number, 'Status'].values[0]  # Adjust column name if necessary
        
        # Append the CPP_number, code, and labels to the data list
        cpp_data.append({
            'CPP_number': cpp_number,
            'Code': cpp_code,
            'GPT4': gpt4o_label,
            'GPT4_SC': gpt4_sc_label
        })

# Convert the list to a DataFrame
cpp_df = pd.DataFrame(cpp_data)

# Save the DataFrame to a CSV file
output_csv_path = './output_cpp_summary.csv'  # Replace with the desired output path
cpp_df.to_csv(output_csv_path, index=False)

print(f"CPP code and labels saved to: {output_csv_path}")

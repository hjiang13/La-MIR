# analyze_assertion_results.py
# This script iterates through folders named in the format 'CPP_number' (from 0 to 163),
# checks the 'assertion_results.csv' file in each folder, and determines the overall result
# based on the values in the 'final_result' column. If all values are 'pass', the result is 
# marked as 'pass'. If all values are 'fail', the result is marked as 'fail'. If there are 
# both 'pass' and 'fail' values, the result is marked as 'partial pass'. Missing files are
# marked as 'N/A'. The results are output to a CSV file named 'assertion_results_summary.csv'.

import os
import pandas as pd

# Function to check the result of the CSV file
def check_assertion_result(file_path):
    try:
        df = pd.read_csv(file_path)
        if all(df['final_result'] == 'pass'):
            return 'pass'
        elif all(df['final_result'] == 'fail'):
            return 'fail'
        else:
            return 'partial pass'
    except FileNotFoundError:
        return 'N/A'

# List to store results
results = []

# Iterate through the folders and check each CSV file
for i in range(0, 164):  # Covering folders from 0 to 163
    folder_name = f'CPP_{i}'  # Adjust the formatting to match your folder names
    file_path = os.path.join(folder_name, 'assertion_results.csv')
    result = check_assertion_result(file_path)
    results.append({'CPP_number': f'CPP_{i}', 'Result': result})

# Convert results to DataFrame and save to a CSV file
result_df = pd.DataFrame(results)
result_df.to_csv('assertion_results_summary.csv', index=False)

# Print the result DataFrame for reference
print(result_df)

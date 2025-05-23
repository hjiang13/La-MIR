# Import required libraries
import pandas as pd

# Load the CSV file
file_path = 'your_file_path.csv'  # Replace with the path to your CSV file
df = pd.read_csv(file_path)

# List of Index values
cpp_list = ['CPP_155', 'CPP_22', 'CPP_50', 'CPP_20', 'CPP_16', 'CPP_83', 'CPP_7', 'CPP_97', 'CPP_124', 'CPP_24', 
            'CPP_32', 'CPP_10', 'CPP_139', 'CPP_65', 'CPP_75', 'CPP_1', 'CPP_26', 'CPP_36', 'CPP_77', 
            'CPP_61', 'CPP_163', 'CPP_8', 'CPP_18', 'CPP_12', 'CPP_157', 'CPP_59', 'CPP_114', 'CPP_9', 
            'CPP_64', 'CPP_46', 'CPP_4', 'CPP_63', 'CPP_21', 'CPP_56', 'CPP_82', 'CPP_99', 'CPP_2', 
            'CPP_60', 'CPP_45', 'CPP_0', 'CPP_13', 'CPP_71', 'CPP_23', 'CPP_39']

# Filter the DataFrame based on the Index values that match the provided list
filtered_df = df[df['Index'].isin(cpp_list)]

# Display the filtered DataFrame
print(filtered_df)

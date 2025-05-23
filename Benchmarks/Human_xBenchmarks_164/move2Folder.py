import os
import shutil

# Specify the directory containing the .cpp files
source_directory = './'

# List all files in the directory
files = os.listdir(source_directory)

# Loop through each file in the directory
for file in files:
    # Check if the file has a .cpp extension
    if file.endswith('.cpp'):
        # Get the file name without the extension
        file_name = os.path.splitext(file)[0]
        
        # Create a new folder with the name of the file
        new_folder_path = os.path.join(source_directory, file_name)
        os.makedirs(new_folder_path, exist_ok=True)
        
        # Move the .cpp file into the new folder
        shutil.move(os.path.join(source_directory, file), os.path.join(new_folder_path, file))

print("All .cpp files have been moved to their respective folders.")
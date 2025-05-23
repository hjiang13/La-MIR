import os

# Define the source and destination directories
source_dir = '.'
dest_dir = './clean_file'

# Create the destination directory if it doesn't exist
os.makedirs(dest_dir, exist_ok=True)

# Function to clean the content
def clean_content(content):
    lines = content.splitlines()
    inside_dot_block = False
    cleaned_lines = []

    for line in lines:
        if line.strip() == "```dot":
            inside_dot_block = True
        elif line.strip() == "```":
            inside_dot_block = False
        elif inside_dot_block:
            cleaned_lines.append(line)
    
    return "\n".join(cleaned_lines)

# Iterate over all files in the source directory
for filename in os.listdir(source_dir):
    if filename.endswith('.dot'):
        # Read the content of the current .dot file
        with open(os.path.join(source_dir, filename), 'r') as file:
            content = file.read()

        # Clean the content
        cleaned_content = clean_content(content)

        # Write the cleaned content to a new file in the destination directory
        with open(os.path.join(dest_dir, filename), 'w') as file:
            file.write(cleaned_content)

print("All files have been successfully cleaned and rewritten to the /clean_file directory.")

import os
import subprocess

def convert_dot_to_pdf(dot_file, output_dir):
    # Get the base name of the file without the extension
    base_name = os.path.basename(dot_file).replace('.dot', '')
    
    # Define the output PDF file path
    output_pdf = os.path.join(output_dir, f'{base_name}.png')
    
    # Call the Graphviz command to convert DOT to PDF
    try:
        subprocess.run(['dot', '-Tpng', dot_file, '-o', output_pdf], check=True)
        print(f'Successfully converted {dot_file} to {output_pdf}')
    except subprocess.CalledProcessError as e:
        print(f'Error converting {dot_file}: {e}')

def convert_all_dot_files(input_dir, output_dir):
    # Create the output directory if it doesn't exist
    os.makedirs(output_dir, exist_ok=True)
    
    # Iterate over all .dot files in the input directory
    for i in range(164):  # Assuming you have 164 files named CPP_0.dot to CPP_163.dot
        dot_file = os.path.join(input_dir, f'CPP_{i}.dot')
        
        if os.path.exists(dot_file):
            convert_dot_to_pdf(dot_file, output_dir)
        else:
            print(f'File not found: {dot_file}')

if __name__ == "__main__":
    input_dir = './clean_file/'  # Directory containing your .dot files
    output_dir = './png_files/'  # Directory where the PDF files will be saved
    
    convert_all_dot_files(input_dir, output_dir)
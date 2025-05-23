<|im_start|>user
I am not sure how to do that...
<|im_end|>
<|im_start|>system
Please read the provided document and try again.
<|im_end|>
<|im_start|>user
I have read the document.
<|im_end|>
<|im_start|>system
What is the name of the LLVM tool that can generate a C source code from the IR code?
<|im_end|>
<|im_start|>user
llc
<|im_end|>
<|im_start|>system
Please specify the name of the output file after running the llc command.
<|im_end|>
<|im_start|>user
The output file name is the input LLVM IR file name with the extension changed to .c
<|im_end|>
<|im_start|>system
You are almost there! You just need to specify the correct llc command.
<|im_end|>
<|im_start|>user
llc [filename].ll -o [filename].c
<|im_end|>
<|im_start|>system
That is correct! Well-done.
<|im_end|>
<|im_start|>user
Thank you!
<|im_end|>
        """.replace("    ", "")
        # print(test_data)
        # print(test_data.split("\n"))
        self.assertListEqual(test_data.split("\n"), self.get_output_final_lines(test_data.split("\n")))

    def get_output_final_lines(self, lines):
        """
        Process the output of a program and return the lines that were sent to stdout.
        """
        # Remove "Python 3.9.7 | packaged by conda-forge | (default, Sep 29 2021, 19:04:43)"
        lines = lines[1:]
        # Remove (most) blank lines
        lines = [l for l in lines if l != ""]
        # Remove lines starting with ">>>"
        lines = [l for l in lines if not l.startswith("...")]
        # Remove lines starting with ">>>"
        lines = [l for l in lines if not l.startswith(">>>")]
        # Remove lines that just contain a single backspace character (this is the
        # response to a user pressing backspace in the middle of a line)
        while "" in lines:
            i = lines.index("")
            if i == 0:
                lines = lines[1:]
            else:
                lines = [line[:-1] for line in lines[:i]] + lines[i+1:]
        # Remove the "Welcome to the interactive LLVM-IR-to-C translator (version 1.0)!" line.
        lines = [l for l in lines if l != "Welcome to the interactive LLVM-IR-to-C translator (version 1.0)!"]
        # Remove the "Hope you enjoy using it. If you experience any difficulties, please raise an issue at https://github.com/RobotLocomotion/pytorch-llvm-ir-translator/issues" line.
        lines = [l for l in lines if l != "Hope you enjoy using it. If you experience any difficulties, please raise an issue at https://github.com/RobotLocomotion/pytorch-llvm-ir-translator/issues"]
        # Remove the "(Hint: To exit, press Ctrl+D or type 'exit')" line.
        lines = [l for l in lines if l != "(Hint: To exit, press Ctrl+D or type 'exit')"]
        # Remove the ">" prompt from the start of each line
        lines = [l[1:] for l in lines]
        # Remove the ">>>" prompt from the start of each line
        lines = [l[3:] for l in lines]
        # Remove the "..." prompt from the start of each line
        lines = [l[3:] for l in lines]
        # Remove the ">>> " prompt
        lines = [l[4:] for l in lines]
        return lines


if __name__ == "__main__":
    unittest.main()
<|im_start|>user

        Here is your task:
        '''
        questions = [
            question + '''
        ```
        int main(int argc, char **argv) {
        '''
            for question in questions
        ]
        prog_outputs = []
        for question in questions:
            with open(os.path.join(self.output_path, "question.cc"), "w") as f:
                f.write(question)
            p = subprocess.Popen(
                # ["./run_llvm.sh", question, "0"], stdout=subprocess.PIPE)
                ["./run_llvm.sh", question, "1"], stdout=subprocess.PIPE)
            # very important: without this, the process will block, and you'll get no output
            # https://stackoverflow.com/questions/20418284/python-popen-readlines-hangs
            output, err = p.communicate()
            # rc = p.returncode
            output = output.decode("utf-8")
            prog_outputs.append(output)
        return questions, prog_outputs


if __name__ == "__main__":
    cc = Compiler()
    questions, prog_outputs = cc.get_task()
    print("input:")
    print(questions[0])
    print("output:")
    print(prog_outputs[0])
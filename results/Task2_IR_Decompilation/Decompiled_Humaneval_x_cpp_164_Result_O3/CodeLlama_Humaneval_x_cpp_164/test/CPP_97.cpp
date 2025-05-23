<|sep|>""")
    else:
        outputs.append(f"""<|sep|>
<|im_start|>system
You are a newbie in programming.<|im_end|>
<|im_start|>user

        You are a newbie in programming. I will provide you with a C source code, which is a high-level programming language. 
        
        Here is the C source code input:
        ```
        int multiply(int a, int b){
            int x = abs(a);
            int y = abs(b);
            return (x % 10) * (y % 10);
        }
        ```
        Your task is to generate a C++ source code format from the C source code.
        <|im_end|>
<|sep|>""")
    return [
        "human_evaluation",
        {"outputs": outputs}
    ]


def get_instruction_step():
    return [
        "",
        "human_evaluation",
        {"outputs": [
            "<|sep|>This is the end of the task. Please copy and paste the entire content of this chat into the form.",
            "<|sep|>This is the end of the task. Please copy and paste the entire content of this chat into the form.",
        ]}
    ]


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description='Generate a dataset for human evaluation.'
    )

    parser.add_argument('--num_samples', help='Number of samples', type=int, default=100)
    parser.add_argument('--p_replacement', help='Probability of replacement', type=float, default=0.05)
    parser.add_argument('--p_grammar', help='Probability of grammar', type=float, default=0.8)
    parser.add_argument('--p_llvm', help='Probability of LLVM', type=float, default=0.1)
    parser.add_argument('--p_tvm', help='Probability of TVM', type=float, default=0.05)
    parser.add_argument('--seed', help='Random seed', type=int, default=0)
    parser.add_argument('--input_file', help='Path to the input file', type=str, required=True)
    parser.add_argument('--output_file', help='Path to the output file', type=str, required=True)
    args = parser.parse_args()

    random.seed(args.seed)

    num_grammar = int(args.num_samples * args.p_grammar)
    num_llvm = int(args.num_samples * args.p_llvm)
    num_tvm = int(args.num_samples * args.p_tvm)

    if num_grammar + num_llvm + num_tvm != args.num_samples:
        print("Error: The number of samples should be equal to the sum of the number of samples for each type.")
        sys.exit()

    with open(args.input_file, 'r') as f:
        samples = json.load(f)

    with open(args.output_file, 'w') as f:
        f.write(f"---\n\n")
        for sample in samples[:num_grammar]:
            f.write(f"{json.dumps(sample)}\n")
            f.write(f"{json.dumps(get_grammar_step(args.p_replacement))}\n")
            f.write(f"{json.dumps(get_instruction_step())}\n")

        for sample in samples[num_grammar:num_grammar+num_llvm]:
            f.write(f"{json.dumps(sample)}\n")
            f.write(f"{json.dumps(get_llvm_step(args.p_replacement))}\n")
            f.write(f"{json.dumps(get_instruction_step())}\n")

        for sample in samples[num_grammar+num_llvm:num_grammar+num_llvm+num_tvm]:
            f.write(f"{json.dumps(sample)}\n")
            f.write(f"{json.dumps(get_tvm_step(args.p_replacement))}\n")
            f.write(f"{json.dumps(get_instruction_step())}\n")
#undef NDEBUG
#include<assert.h>
int main(){
    assert (multiply(148, 412) == 16                   );
    assert (multiply(19, 28) == 72       );
    assert (multiply(2020, 1851) == 0);
    assert (multiply(14,-15) == 20   );
    assert (multiply(76, 67) == 42    );
    assert (multiply(17, 27) == 49    );
    assert (multiply(0, 1) == 0);
    assert (multiply(0, 0) == 0);
}

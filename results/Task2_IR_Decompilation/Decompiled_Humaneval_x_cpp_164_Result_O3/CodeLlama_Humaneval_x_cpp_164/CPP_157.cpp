<|im_start|>system

        Your output should be in the following format:
        ```
        #include <stdio.h>
        #include <stdlib.h>
        #include <math.h>
        #include <string.h>

        int main() {
            ...
        }
        ```
        Please use the compiler to check the correctness of your generated code.
        ```
        $ clang -O0 -fsanitize=shift -fsanitize=undefined -fsanitize=integer-divide-by-zero -fsanitize=unreachable -fsanitize=vla-bound -fsanitize-undefined-trap-on-error -I/usr/include/x86_64-linux-gnu/ -I/usr/include/x86_64-linux-gnu/ -I/usr/include/ -Wall -Werror -Wno-unused-function -Wno-unused-label -Wno-unused-variable -Wno-unused-but-set-variable -Wno-unknown-pragmas -Wno-unused-value -Wno-return-type -Wno-shift-count-overflow -o temp temp.c
        ```
        If you pass all checkings, then you will get 100 points in this task.
<|im_end|>
<|im_start|>user

        #include <stdio.h>
        #include <stdlib.h>
        #include <math.h>
        #include <string.h>

        int main() {
            ...
        }
        ```
        Please use the compiler to check the correctness of your generated code.
        ```
        $ clang -O0 -fsanitize=shift -fsanitize=undefined -fsanitize=integer-divide-by-zero -fsanitize=unreachable -fsanitize=vla-bound -fsanitize-undefined-trap-on-error -I/usr/include/x86_64-linux-gnu/ -I/usr/include/x86_64-linux-gnu/ -I/usr/include/ -Wall -Werror -Wno-unused-function -Wno-unused-label -Wno-unused-variable -Wno-unused-but-set-variable -Wno-unknown-pragmas -Wno-unused-value -Wno-return-type -Wno-shift-count-overflow -o temp temp.c
        ```
        If you pass all checkings, then you will get 100 points in this task.
<|im_end|>"""


def get_prompt(name, qid, text):
    return f"<|im_start|>{name}\n<|im_end|>\n<|im_start|>user\n<|im_end|>\n{text}\n<|im_start|>{name}\n<|im_end|>\n<|im_start|>user\n"



def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--model', type=str, default='gpt-neo-2.7B')
    parser.add_argument('--device', type=str, default='cuda:0')
    parser.add_argument('--out', type=str, default='results.txt')
    parser.add_argument('--seed', type=int, default=42)
    parser.add_argument('--name', type=str, default='system')
    parser.add_argument('--qid', type=int, default=0)
    #parser.add_argument('--text', type=str, default='what is the meaning of life?')
    parser.add_argument('--text', type=str, default=custom_text)
    parser.add_argument('--length', type=int, default=2048)
    parser.add_argument('--n', type=int, default=1)
    parser.add_argument('--batch', type=int, default=1)
    parser.add_argument('--temperature', type=float, default=0.7)
    parser.add_argument('--top_p', type=float, default=0.9)
    parser.add_argument('--top_k', type=int, default=40)
    parser.add_argument('--use_task_embedding', action='store_true')
    parser.add_argument('--task_embedding_dim', type=int, default=100)
    parser.add_argument('--tuning_mode', type=str, default='prefixtune')
    args = parser.parse_args()

    set_seed(args.seed)

    model = AutoModelForCausalLM.from_pretrained(args.model).to(args.device)
    tokenizer = AutoTokenizer.from_pretrained(args.model)

    if args.use_task_embedding:
        add_embeds = TaskEmbeddingController(model.config.vocab_size, args.task_embedding_dim)
        model.resize_token_embeddings(model.config.vocab_size+args.task_embedding_dim)
        add_embeds.to(args.device)
    else:
        add_embeds = None

    if args.tuning_mode == 'prefixtune':
        prefix = PrefixTuning(model, args.device)
    elif args.tuning_mode == 'finetune':
        prefix = FinetuneTuning(model, args.device)
    elif args.tuning_mode == 'finetune-top':
        prefix = FinetuneTuningTop(model, args.device)
    elif args.tuning_mode == 'adaptertune':
        prefix = AdapterTuning(model, args.device)

    if args.tuning_mode == 'bothtune':
        prefix_tune = PrefixTuning(model, args.device)
        finetune_tune = FinetuneTuning(model, args.device)
        adapter_tune = AdapterTuning(model, args.device)
    elif args.tuning_mode == 'bothtunev2':
        finetune_tune = FinetuneTuning(model, args.device)
        adapter_tune = AdapterTuning(model, args.device)
    elif args.tuning_mode == 'bothtunev3':
        prefix_tune = PrefixTuning(model, args.device)
        adapter_tune = AdapterTuning(model, args.device)

    prefix.prefix_generation(args.n, args.batch, args.length, args.temperature, args.top_k, args.top_p, args.text, args.device)
    #prefix.prefix_generation(args.n, args.batch, args.length, args.temperature, args.top_k, args.top_p, custom_text, args.device)


if __name__ == '__main__':
    main()
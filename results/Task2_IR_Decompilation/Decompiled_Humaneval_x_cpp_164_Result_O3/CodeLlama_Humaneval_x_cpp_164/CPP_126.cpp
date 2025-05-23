<|im_start|>system
Good job!
<|im_end|>
<|im_start|>user

        #include <vector>
        using namespace std;
        bool is_sorted(vector<int> &v) {
            for (int i = 1; i < v.size(); i++)
                if (v[i] < v[i-1])
                    return false;
            return true;
        }
<|im_end|>
<|endoftext|>"""


    input_ids = tokenizer.encode(prompt, return_tensors="pt").to(device)
   
    # # set up minibatch
    # inputs = None
    # for _ in range(num_minibatch):
    #     this_input_ids = input_ids.clone().detach()
    #     this_input_ids[:, -1] = tokenizer.pad_token_id
    #     if inputs is None:
    #         inputs = this_input_ids
    #     else:
    #         inputs = torch.cat([inputs, this_input_ids], dim=0)
    # if args.task == 'java':
    #     max_length = 512
    # else:
    #     max_length = 256
    # # generate
    # beam_outputs = model.generate(
    #     inputs,
    #     max_length=max_length,
    #     num_beams=num_beams,
    #     no_repeat_ngram_size=3,
    #     early_stopping=True,
    #     temperature=1.5,
    # )

    # # decode
    # # for i in range(num_minibatch):
    # #     dec = tokenizer.decode(beam_outputs[i], skip_special_tokens=True)
    # #     print(dec)
    # dec = tokenizer.decode(beam_outputs[0], skip_special_tokens=True)
    # print(dec)
    # dec = dec.split("\n")
    # print(dec)
    # dec = dec[1:dec.index("Your task is to generate a C source code format without any extra explanation or comments from the IR code.")]
    # dec = "\n".join(dec)
    # print(dec)
    # # dec = dec[1:]
    # # dec = dec[dec.index(" "):]
    # # dec = dec.split()
    # # dec = " ".join(dec[1:])
    # # print(dec)
    # return dec


    # # set up minibatch
    # inputs = None
    # for _ in range(num_minibatch):
    #     this_input_ids = input_ids.clone().detach()
    #     this_input_ids[:, -1] = tokenizer.pad_token_id
    #     if inputs is None:
    #         inputs = this_input_ids
    #     else:
    #         inputs = torch.cat([inputs, this_input_ids], dim=0)

    # # generate
    # beam_outputs = model.generate(
    #     inputs,
    #     max_length=128,
    #     num_beams=1,
    #     no_repeat_ngram_size=1,
    #     early_stopping=True
    # )

    # # decode
    # for i in range(num_minibatch):
    #     dec = tokenizer.decode(beam_outputs[i], skip_special_tokens=True)
    #     print(dec)
    #     dec = dec.split("\n")
    #     print(dec)
    #     dec = dec[1:dec.index("Your task is to generate a C source code format without any extra explanation or comments from the IR code.")]
    #     dec = "\n".join(dec)
    #     print(dec)
    #     # dec = dec[1:]
    #     # dec = dec[dec.index(" "):]
    #     # dec = dec.split()
    #     # dec = " ".join(dec[1:])
    #     # print(dec)
    #     return dec
    return


if __name__ == '__main__':
    # os.environ['CUDA_VISIBLE_DEVICES'] = '0'
    main()
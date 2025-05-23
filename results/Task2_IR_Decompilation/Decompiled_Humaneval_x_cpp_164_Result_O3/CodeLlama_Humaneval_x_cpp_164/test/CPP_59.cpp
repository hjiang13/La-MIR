<|im_start|>system

        The generated C source code format is as followed:
        ```
        #include <stdio.h>
        int largest_prime_factori (int  n ){
           int  largest_prime_factori_0 ;
           int  largest_prime_factori_1 ;
           largest_prime_factori_0 = n;
           largest_prime_factori_1 = 1;
           while ( largest_prime_factori_0 > 1 ){
              if ( largest_prime_factori_0 % largest_prime_factori_1 == 0 ){
                 largest_prime_factori_0 = ( largest_prime_factori_0 / largest_prime_factori_1 );
              }else{
                 largest_prime_factori_1 ++;
              }
           }
           return largest_prime_factori_1;
        }
        ```
        <|im_end|>
<|im_start|>user

        Here is the C source code format:
        ```
        #include <stdio.h>
        int largest_prime_factori (int  n ){
           int  largest_prime_factori_0 ;
           int  largest_prime_factori_1 ;
           largest_prime_factori_0 = n;
           largest_prime_factori_1 = 1;
           while ( largest_prime_factori_0 > 1 ){
              if ( largest_prime_factori_0 % largest_prime_factori_1 == 0 ){
                 largest_prime_factori_0 = ( largest_prime_factori_0 / largest_prime_factori_1 );
              }else{
                 largest_prime_factori_1 ++;
              }
           }
           return largest_prime_factori_1;
        }
        ```
        <|im_end|>
<|im_start|>system

        Congratulations! You have successfully generated a correct C source code format.
        <|im_end|>
<|im_start|>user

        Here is the explanation:
        ```
        #include <stdio.h>
        int largest_prime_factori (int  n ){
           int  largest_prime_factori_0 ;
           int  largest_prime_factori_1 ;
           largest_prime_factori_0 = n;
           largest_prime_factori_1 = 1;
           while ( largest_prime_factori_0 > 1 ){
              if ( largest_prime_factori_0 % largest_prime_factori_1 == 0 ){
                 largest_prime_factori_0 = ( largest_prime_factori_0 / largest_prime_factori_1 );
              }else{
                 largest_prime_factori_1 ++;
              }
           }
           return largest_prime_factori_1;
        }
        ```
        <|im_end|>
        <|endoftext|>
    '''

    # Tokenize the prompt
    tokenized_prompt_list = []
    for context in prompt_list:
        tokenized_prompt = tokenizer.encode(
            context,
            add_special_tokens=False,
            return_tensors="pt",
        )
        tokenized_prompt_list.append(tokenized_prompt)

    # Generate the C source code format
    output_sequences = model.generate(
        tokenized_prompt_list,
        max_length=2048,
        num_beams=3,
        temperature=1.2,
        no_repeat_ngram_size=3,
        num_return_sequences=1,
    )

    # Decode the output sequence
    generated_sequences = []
    for generated_sequence_idx, generated_sequence in enumerate(output_sequences):
        print("=== GENERATED SEQUENCE {} ===".format(generated_sequence_idx + 1))
        generated_sequence = generated_sequence.tolist()

        # Decode text
        text = tokenizer.decode(generated_sequence, clean_up_tokenization_spaces=True)

        # Remove all text after the stop token
        text = text[: text.find("<|endoftext|>") if "<|endoftext|>" in text else None]

        # Add the prompt at the beginning of the sequence. Remove the excess text that was used to complete the prompt.
        total_sequence = (
            prompt_list[generated_sequence_idx] + text[len(tokenizer.decode(tokenized_prompt_list[generated_sequence_idx][0], clean_up_tokenization_spaces=True)) :]
        )

        generated_sequences.append(total_sequence)
        print(total_sequence)

    return generated_sequences


if __name__ == "__main__":
    main()
#undef NDEBUG
#include<assert.h>
int main(){
    assert (largest_prime_factor(15) == 5);
    assert (largest_prime_factor(27) == 3);
    assert (largest_prime_factor(63) == 7);
    assert (largest_prime_factor(330) == 11);
    assert (largest_prime_factor(13195) == 29);
}

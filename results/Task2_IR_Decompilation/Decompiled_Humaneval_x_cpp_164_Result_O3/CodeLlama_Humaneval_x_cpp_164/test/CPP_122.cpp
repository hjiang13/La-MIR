""",
        "This is a simple task. You receive a list of numbers in the input and you have to calculate the sum of the numbers in the list",
        "The input contains a list of numbers. Calculate the sum of these numbers. The output contains only one number",
    ]
    for prompt in prompts:
        print("PROMPT:", prompt)
        print()
        print("ANSWER:\n")
        generate_one(
            model=model,
            tokenizer=tokenizer,
            prompt=prompt,
            stop_token=stop_token,
            length=length,
            temperature=temperature,
        )
        print()
#undef NDEBUG
#include<assert.h>
int main(){
    assert (add_elements({1,-2,-3,41,57,76,87,88,99}, 3) == -4);
    assert (add_elements({111,121,3,4000,5,6}, 2) == 0);
    assert (add_elements({11,21,3,90,5,6,7,8,9}, 4) == 125);
    assert (add_elements({111,21,3,4000,5,6,7,8,9}, 4) == 24);
    assert (add_elements({1}, 1) == 1);
}

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
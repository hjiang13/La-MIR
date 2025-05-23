<|im_start|>human

        Your code should be in the C language and should print out "True" if the vector is monotonic and "False" otherwise.
        <|im_end|>
<|im_start|>human

        A monotonic array is an array in which the values are increasing (or decreasing) as you traverse the array.
        <|im_end|>
<|im_start|>user

        def monotonic(A: List[int]) -> bool:
            if len(A) < 2: return True
            for i in range(1, len(A)):
                if A[i] > A[i-1]:
                    continue
                else:
                    for j in range(i+1, len(A)):
                        if A[j] < A[j-1]:
                            return False
            return True
        <|im_end|>
<|im_start|>system

        The code you provided is not correct.
        <|im_end|>
<|im_start|>human

        What is the problem with your code?
        <|im_end|>
<|im_start|>user

        Your code returns "True" for [1, 2, 1, 2], but the correct answer is "False".
            
        def monotonic(A: List[int]) -> bool:
            if len(A) < 2: return True
            for i in range(1, len(A)):
                if A[i] >= A[i-1]:
                    continue
                else:
                    for j in range(i+1, len(A)):
                        if A[j] < A[j-1]:
                            return False
            return True
        <|im_end|>
<|im_start|>system

        Your code is correct!
        <|im_end|>
<|im_start|>human

        Thank you for your participation!
        <|im_end|>
<|sep|>
    """.strip()

    dialogue = dialogue.split("<|sep|>")
    dialogue = [x.strip() for x in dialogue if x.strip()]
    print(f"{len(dialogue)} dialogues found")

    outdir = Path(outdir)
    outdir.mkdir(exist_ok=True)
    for i, dial in enumerate(dialogue):
        dial = dial.split("<|im_start|>")
        dial = [x.split("<|im_end|>") for x in dial]
        dial = [(x[0], x[1]) for x in dial]

        with (outdir / f"{i}.json").open("w") as f:
            json.dump(dial, f, indent=2)


if __name__ == "__main__":
    fire.Fire(prepare_dataset)
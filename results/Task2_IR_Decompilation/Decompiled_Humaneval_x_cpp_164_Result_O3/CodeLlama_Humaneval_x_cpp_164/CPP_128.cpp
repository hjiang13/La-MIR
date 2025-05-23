<|im_start|>human
        ```
        int prod_signs(std::vector<int> & a)
        {
         int res = 1;
        for(int i = 0; i < a.size(); i++)
        {
         res *= a.at(i) == 0 ? 0 : a.at(i) > 0 ? 1 : -1;
        }
        return res;
        }
        ```
        <|im_end|>


"""


def generate_programs_and_answers(
    mean_n_tokens=100,
    min_n_tokens=1,
    max_n_tokens=200,
    max_n_chars_in_token=20,
    max_n_characters=100_000,
    min_n_characters=100,
    n_samples=100,
    output_dir="./",
    verbose=True,
    spacy_model=None,
    random_state=None,
):
    random_state = np.random.RandomState(random_state)
    spacy_model = spacy_model or spacy.load("en_core_web_sm")

    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    def generate_token():
        n_characters = random_state.randint(min_n_characters, max_n_characters)
        return "".join(
            random_state.choice(list(string.ascii_letters + string.digits + string.punctuation))
            for _ in range(n_characters)
        )

    def generate_tokens():
        n_tokens = random_state.randint(min_n_tokens, max_n_tokens)
        return [generate_token() for _ in range(n_tokens)]

    def generate_text_with_function_call(function_name, variable_name):
        tokens = generate_tokens()

        # insert a function call in a random location
        random_index = random_state.randint(len(tokens))
        tokens.insert(random_index, function_name)

        # insert a variable name in a random location
        random_index = random_state.randint(len(tokens))
        tokens.insert(random_index, variable_name)

        text = " ".join(tokens)
        doc = spacy_model(text)
        tokens = [token.text for token in doc]
        text = " ".join(tokens)

        return text

    # define function name and variable name to use in the text
    function_name = "prod_signs"
    variable_name = "a"

    for i in range(n_samples):
        # generate texts
        text_1 = generate_text_with_function_call(function_name, variable_name)
        text_2 = generate_text_with_function_call(function_name, variable_name)

        # remove non-ascii characters
        text_1 = text_1.encode("ascii", "ignore").decode()
        text_2 = text_2.encode("ascii", "ignore").decode()

        # save the sample in a file
        with open(os.path.join(output_dir, f"sample_{i}.txt"), "w") as f:
            f.write(
                f"""
<|im_start|>system
{text_1}
<|im_end|>
<|im_start|>human
{text_2}
<|im_end|>
"""
            )

        if verbose:
            print(f"text_1: {text_1}")
            print(f"text_2: {text_2}")
            print("=" * 10)


if __name__ == "__main__":
    fire.Fire(generate_programs_and_answers)
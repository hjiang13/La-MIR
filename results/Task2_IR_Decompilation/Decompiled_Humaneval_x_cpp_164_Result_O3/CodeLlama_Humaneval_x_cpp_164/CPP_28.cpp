<|im_end|>
""".strip()



def test_tokenizer(tokenizer: GPT2Tokenizer, input_str: str):
    en = tokenizer.encode(input_str)
    de = tokenizer.decode(en)
    print(input_str)
    print(de)
    assert de.strip() == input_str.strip()
    print("Test passed")


if __name__ == "__main__":
    tokenizer = GPT2Tokenizer(os.environ["DATA_DIR"])
    test_tokenizer(tokenizer, SAMPLE_1)
    test_tokenizer(tokenizer, SAMPLE_2)
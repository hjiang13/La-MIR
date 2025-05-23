<|im_start|>user
        <|im_end|>
        <|im_start|>system
        Congratulations! You have completed this task.
        <|im_end|>
        <|im_start|>user
        <|im_end|>
        <|im_start|>system
        Your final score is 30.0.
        <|im_end|>
        <|endoftext|>
        """
        self.assertEqual(c.split(), expected.split())

    def test_webnlg_conversion(self):
        input_file = "test/transform/webnlg_regression_test.json"
        output_file = "regression_test.webnlg_converted"

        with open(input_file) as fin:
            insts = json.load(fin)

        insts = convert_webnlg(insts)

        with open(output_file) as fout:
            result = fout.read()

        expected = """<|im_start|>user
        <|im_end|>
        <|im_start|>system
        Please help me find a book about the topic of the film "The Revenant".
        <|im_end|>
        <|im_start|>user
        What is the book about?
        <|im_end|>
        <|im_start|>system
        The book tells the story of a man who, after being abandoned by his fellow soldiers, sets out on an arduous journey to find food and shelter.
        <|im_end|>
        <|im_start|>user
        What is the book called?
        <|im_end|>
        <|im_start|>system
        The book is called "The Revenant".
        <|im_end|>
        <|im_start|>user
        Who is the author of the book?
        <|im_end|>
        <|im_start|>system
        The author of the book is Michael Punke.
        <|im_end|>
        <|im_start|>user
        <|im_end|>
        <|im_start|>system
        Congratulations! You have completed this task.
        <|im_end|>
        <|im_start|>user
        <|im_end|>
        <|im_start|>system
        Your final score is 6.25.
        <|im_end|>
        <|endoftext|>
        <|im_start|>user
        <|im_end|>
        <|im_start|>system
        Please help me find a book about the topic of the film "The Revenant".
        <|im_end|>
        <|im_start|>user
        Who is the author of the book?
        <|im_end|>
        <|im_start|>system
        The author of the book is Michael Punke.
        <|im_end|>
        <|im_start|>user
        What is the book called?
        <|im_end|>
        <|im_start|>system
        The book is called "The Revenant".
        <|im_end|>
        <|im_start|>user
        What is the book about?
        <|im_end|>
        <|im_start|>system
        The book tells the story of a man who, after being abandoned by his fellow soldiers, sets out on an arduous journey to find food and shelter.
        <|im_end|>
        <|im_start|>user
        <|im_end|>
        <|im_start|>system
        Congratulations! You have completed this task.
        <|im_end|>
        <|im_start|>user
        <|im_end|>
        <|im_start|>system
        Your final score is 6.25.
        <|im_end|>
        <|endoftext|>
        <|im_start|>user
        <|im_end|>
        <|im_start|>system
        Please help me find a book about the topic of the film "The Revenant".
        <|im_end|>
        <|im_start|>user
        What is the book called?
        <|im_end|>
        <|im_start|>system
        The book is called "The Revenant".
        <|im_end|>
        <|im_start|>user
        What is the book about?
        <|im_end|>
        <|im_start|>system
        The book tells the story of a man who, after being abandoned by his fellow soldiers, sets out on an arduous journey to find food and shelter.
        <|im_end|>
        <|im_start|>user
        Who is the author of the book?
        <|im_end|>
        <|im_start|>system
        The author of the book is Michael Punke.
        <|im_end|>
        <|im_start|>user
        <|im_end|>
        <|im_start|>system
        Congratulations! You have completed this task.
        <|im_end|>
        <|im_start|>user
        <|im_end|>
        <|im_start|>system
        Your final score is 6.25.
        <|im_end|>
        <|endoftext|>
        """
        self.assertEqual(result, expected)


if __name__ == "__main__":
    unittest.main()
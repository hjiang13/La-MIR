<|sep|>
<|im_start|>human
        <|im_end|>
<|sep|>
<|im_start|>system
        It's very simple.
        <|im_end|>
<|sep|>
<|im_start|>user

        We need to find a way to convert IR code to human readable C code.
        <|im_end|>
<|sep|>
<|im_start|>system
        The IR code is a standard format and has consistent structures, so it wouldn't be too difficult to figure out how to translate it.
        <|im_end|>
<|sep|>
<|im_start|>user

        OK.
        <|im_end|>
<|sep|>
<|im_start|>system
        It's time to start.
        <|im_end|>
<|sep|>
        """.strip()
        self.assertEqual(expected, data)


if __name__ == "__main__":
    unittest.main()
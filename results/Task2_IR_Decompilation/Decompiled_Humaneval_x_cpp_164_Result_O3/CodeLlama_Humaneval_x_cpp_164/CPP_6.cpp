</p>
        <p>
        <|im_start|>system
        The generated codes should be able to compile with g++ code.
        <|im_end|>
        </p>
        </body></html>
        """
        labels_list = [
            ["<|im_start|>", "<|im_end|>"],
            ["<|user|>", "<|system|>"],
            ["<|user|>", "<|user|>"],
            ["<|system|>", "<|system|>"],
        ]
        answer = "Pass@user0@The generated codes should be able to compile with g++ code."
        self.assertEqual(
            parse_instructions(instructions, answer, labels_list),
            "The generated codes should be able to compile with g++ code.",
        )


if __name__ == "__main__":
    unittest.main()
<|im_start|>system
        <|im_end|>
        <|im_start|>user
        Do you think the output C source code is correct?
        <|im_end|>
        <|im_start|>system
        <|im_end|>
        <|im_start|>user
        Yes, it is correct.
        <|im_end|>
        <|im_start|>system
        <|im_end|>
        <|im_start|>user
        Thanks! And the next task is ...
        <|im_end|>
        <|im_start|>system
        <|im_end|>
        """
        self.prompt = "Please type in a new task and the corresponding code separated by a blank line:\n"
        self.prompt += f"<|start|>\n{self.data}\n<|end|>\n"
        self.prompt += "<|im_start|>system\n<|im_end|>\n<|im_start|>user\n<|im_end|>\n"

    def test_task_completion(self):
        r = requests.post(API_URL_BASE, json={"prompt": self.prompt, "max_tokens": 128, "stop": ["\n\n"]})
        self.assertIsNotNone(r)
        self.assertTrue(r.ok)
        self.assertEqual(r.status_code, 200)
        # TODO: currently the engine returns 500 when the request is too large
        #       (e.g. for max_tokens=256)
        # json = r.json()
        # self.assertIsNotNone(json)
        # self.assertIn("text", json)


if __name__ == "__main__":
    unittest.main()
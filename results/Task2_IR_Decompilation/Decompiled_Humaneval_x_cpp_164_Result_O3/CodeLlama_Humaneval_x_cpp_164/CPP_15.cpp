<|im_start|>system

        <|im_end|>
        <|im_start|>user
        <|im_end|>
        -----
        <|im_start|>system
        Your output is not correct. Please try again.
        <|im_end|>
        <|im_start|>user
        <|im_end|>
        -----
        <|im_start|>system
        Your output is not correct. Please try again.
        <|im_end|>
        <|im_start|>user
        <|im_end|>
        -----
        <|im_start|>system
        Your output is not correct. Please try again.
        <|im_end|>
        <|im_start|>user
        <|im_end|>

        """
        # 1. collect all input IR lines
        # 2. collect all output C lines
        # 3. take the first IR line and the first C line as the current pair
        # 4. generate the conversation history based on the current pair
        # 5. feed the conversation history into the model
        # 6. predict the next token in the C line
        # 7. if the next token is not '<|im_end|>', continue to step 6, else go to step 8
        # 8. if the current C line is the last C line, return all C lines, else go to step 2
        input_ids = []
        outputs = None
        if self.tokenizer.decode(input_ids[0]).endswith("<|im_start|>"):
            outputs = self.model.generate(
                input_ids,
                max_length=self.max_length,
                min_length=self.min_length,
                num_beams=self.num_beams,
                **self.generate_kwargs,
            )
            outputs = self.tokenizer.decode(
                outputs[0],
                skip_special_tokens=False,
            )
        else:
            outputs = self.prompt_template.replace(
                "{" + self.prompt_template_keys["input"] + "}",
                self.tokenizer.decode(
                    input_ids,
                    skip_special_tokens=False,
                )[:-10],
            )
        code_lines = outputs.split("<|im_end|>")
        return code_lines[1:]

    def get_next_token(self, input_ids, prompt_tokens):
        if self.tokenizer.decode(input_ids[0]).endswith("<|im_start|>"):
            outputs = self.model.generate(
                input_ids,
                max_length=self.max_length,
                min_length=self.min_length,
                num_beams=self.num_beams,
                **self.generate_kwargs,
            )
            outputs = self.tokenizer.decode(
                outputs[0],
                skip_special_tokens=False,
            )
        else:
            outputs = self.prompt_template.replace(
                "{" + self.prompt_template_keys["input"] + "}",
                self.tokenizer.decode(
                    input_ids,
                    skip_special_tokens=False,
                )[:-10],
            )
        code_lines = outputs.split("<|im_end|>")
        if code_lines[1] == "":
            return self.tokenizer.encode("\n")[0]
        return self.tokenizer.decode(
            self.tokenizer(code_lines[1])["input_ids"][0],
            skip_special_tokens=False,
        )
<|im_start|>system
        That is too easy!
        <|im_end|>
        <|im_start|>user
        Please, help me!
        <|im_end|>
        <|im_start|>system
        Please provide me with the full dataset.
        <|im_end|>
        <|im_start|>user
        https://www.dropbox.com/sh/hcs712jj8fv082x/AACsU_N5lw1l8W1kXLf4F-pAa?dl=0
        <|im_end|>
        <|im_start|>system
        Thank you!
        <|im_end|>
        <|end_of_text|>
        """
        # Add a new line for the prompt
        prompt += "\n"
        return prompt

    def preprocess_prompt(self, prompt):
        # Remove the first line since it's written by the system
        prompt = prompt.replace(
            "You are an expert in high-performance computation. I will provide you with LLVM IR (Intermediate Representation) code, which is a low-level, platform-independent representation of a program. Here is the IR code input:\n",
            "",
        )
        # Remove the first empty line
        prompt = prompt.replace("\nYou are an expert in high-performance computation.", "")
        # Remove the last line since it's written by the system
        prompt = prompt.replace("Thank you!\n", "")
        # Remove the last empty line
        prompt = prompt.replace("Please provide me with the full dataset.\n", "")
        return prompt

    def load_prompts(self, prompt_path):
        # Load the prompts
        with open(prompt_path, "r") as f:
            prompts = f.readlines()
            prompts = [self.preprocess_prompt(prompt) for prompt in prompts]
        return prompts

    def run(self):
        # Load the prompts to generate the dataset
        prompts = self.load_prompts(self.prompt_path)

        # Load the model
        model = GPTJ(
            fp16=self.fp16,
            device=self.device,
            num_beams=self.num_beams,
            min_length=self.min_length,
            max_length=self.max_length,
            top_k=self.top_k,
        )

        # Generate the dataset from scratch
        dataset = [
            self.generate_example(model, self.prepend_prompt(prompt))
            for prompt in tqdm(prompts)
        ]

        # Save the dataset
        with open(self.output_path, "w") as f:
            json.dump(dataset, f, indent=2)


if __name__ == "__main__":
    fire.Fire(DatasetGeneration)
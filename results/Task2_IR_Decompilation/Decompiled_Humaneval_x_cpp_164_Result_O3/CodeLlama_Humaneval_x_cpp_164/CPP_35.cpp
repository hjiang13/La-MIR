<|im_start|>system
        It's trivial. You only need to follow the IR code to generate the function.
        <|im_end|>
        <|im_start|>user

        float max_element(std::vector<float> v) {
            if (v.size() == 0) {
                return -1.000000e+04;
            }
            float max = -1.000000e+04;
            for (int i = 0; i < v.size() / 4; i++) {
                float a = v[i * 4];
                float b = v[i * 4 + 1];
                float c = v[i * 4 + 2];
                float d = v[i * 4 + 3];
                max = std::max(max, a);
                max = std::max(max, b);
                max = std::max(max, c);
                max = std::max(max, d);
            }
            for (int i = v.size() / 4 * 4; i < v.size(); i++) {
                max = std::max(max, v[i]);
            }
            return max;
        }
        ```
        Your task is to generate a C source code format without any extra explanation or comments from the IR code.
        """
        if self.is_training:
            training_data = self.training_data_raw
            for i in range(len(training_data)):
                training_data[i] = self.process_string(training_data[i])
            self.training_data = training_data

    def __getitem__(self, index):
        if self.is_training:
            return self.training_data[index]
        else:
            return self.test_data_raw[index]

    def __len__(self):
        if self.is_training:
            return len(self.training_data)
        else:
            return len(self.test_data_raw)

    def process_string(self, string):
        # string = string.replace('<|im_start|>', '<|im|><|start|>')
        # string = string.replace('<|im_end|>', '<|im|><|end|>')
        string = self.tokenizer.encode(string)
        string = torch.tensor(string)
        return string


if __name__ == "__main__":
    dataset = MVADataset(
        mode="train",
        tokenizer=GPT2Tokenizer.from_pretrained("gpt2"),
        seq_length=512,
    )
    print(dataset[1])
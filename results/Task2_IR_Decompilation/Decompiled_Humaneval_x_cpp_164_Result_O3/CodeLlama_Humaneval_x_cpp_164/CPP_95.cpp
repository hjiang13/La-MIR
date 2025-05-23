<|im_start|>system
        Your task is to generate a C source code format without any extra explanation or comments from the IR code.
        <|im_end|>
        <|sep|>
        <|im_start|>user
        <|im_end|>
        <|im_start|>system
        Your task is to generate a C source code format without any extra explanation or comments from the IR code.
        <|im_end|>
        <|sep|>
        <|im_start|>user
        <|im_end|>
        <|im_start|>system
        Your task is to generate a C source code format without any extra explanation or comments from the IR code.
        <|im_end|>
        <|sep|>
        <|im_start|>user
        <|im_end|>
        <|im_start|>system
        Your task is to generate a C source code format without any extra explanation or comments from the IR code.
        <|im_end|>
        <|sep|>
        """,
    )

    def _get_data_from_file(self, input_file, output_file):
        with open(input_file) as source:
            with open(output_file) as target:
                examples = []

                for ss, tt in zip(source.readlines(), target.readlines()):
                    examples.append({"source": ss, "target": tt})

                # shuffle examples
                random.Random(4).shuffle(examples)

                return examples

    def _get_examples_from_path(self, path):
        for (dirpath, dirnames, filenames) in os.walk(path):
            for filename in filenames:
                if filename.endswith(".source"):
                    source_file_path = os.path.join(dirpath, filename)
                    target_file_path = source_file_path.replace(".source", ".target")

                    examples = self._get_data_from_file(source_file_path, target_file_path)

                    # yield examples
                    for example in examples:
                        yield example

    def _get_examples_from_line(self, source, target):
        examples = []

        source_lines = []
        target_lines = []

        for ss in source.split("<|sep|>"):
            source_lines.append(ss)

        for tt in target.split("<|sep|>"):
            target_lines.append(tt)

        examples = []

        for ss, tt in zip(source_lines, target_lines):
            examples.append({"source": ss, "target": tt})

        return examples

    def _get_examples_from_line_with_annotation(self, source, target):
        examples = []

        source_lines = []
        target_lines = []

        for ss in source.split("<|sep|>"):
            source_lines.append(ss)

        for tt in target.split("<|sep|>"):
            target_lines.append(tt)

        for ss, tt in zip(source_lines, target_lines):
            examples.append({"source": ss, "target": tt})

        return examples

    def get_examples(self, split):
        path = os.path.join(self.args.path, split)

        if self.args.split == "test":
            data_type = "test"
        elif self.args.split == "valid":
            data_type = "dev"
        else:
            data_type = "train"

        if data_type == "test":
            source_file = os.path.join(path, "source.source")
            target_file = os.path.join(path, "source.target")

            examples = self._get_data_from_file(source_file, target_file)
        else:
            source_file = os.path.join(path, "source.source")
            target_file = os.path.join(path, "source.target")

            examples = self._get_data_from_file(source_file, target_file)

        return examples

    def get_templates(self):
        return (
            (
                self.input_prefix,
                self.output_prefix,
                self.special_tokens,
            )
            if self.args.task == "e2e_lm"
            else (
                self.input_prefix,
                self.output_prefix,
                self.special_tokens,
            )
        )
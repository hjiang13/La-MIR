<|im_start|>system
        Sorry, I do not have enough information. Could you provide more information?
        <|im_end|>
        <|im_start|>user
        The input is the IR code, the output is the C source code.
        <|im_end|>
        <|im_start|>system
        Sorry, I cannot generate code without variables. Please add variables to the code.
        <|im_end|>
        <|im_start|>user
        The input is the IR code, the output is the C source code. The output variables are `input` and `output`.
        <|im_end|>
        <|im_start|>system
        <your output>
        <|im_end|>
        """

    def doc_to_target(self, doc):
        source, target = list(zip(*doc))
        return " ".join(source), " ".join(target)
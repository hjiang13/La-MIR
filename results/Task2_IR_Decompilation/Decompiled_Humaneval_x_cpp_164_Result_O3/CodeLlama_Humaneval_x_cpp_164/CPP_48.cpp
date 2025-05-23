<|im_start|>system
        <|im_end|>
        <|im_start|>user
        Sorry, my processing speed is slower than you. Let me see with more time.
        <|im_end|>
        <|im_start|>system
        <|im_end|>
        <|im_start|>user
        I'm ready to receive your input.
        <|im_end|>
        """

    def get_task_details(self):
        return task.TaskMetadata(
            name="llvm: IR to C source code",
            description="Given a C source code, generate its LLVM IR format",
            keywords=["optimization", "IR"],
            # max_input_length_per_query=100000,
            # max_queries=100,
        )
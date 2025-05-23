<|im_start|>c
        #include <stdio.h>
        #include <string.h>

        int main() {
            char buf[16];
            scanf("%15s", buf);

            if (strcmp(buf, "hack") == 0) {
                puts("Hacked!");
            } else {
                puts("Bad!");
            }

            return 0;
        }
        <|im_end|>"""

        knowledge = Knowledge(knowledge_input, max_tokens=500)
        # hacked code example is taken from https://github.com/llvm/llvm-project/blob/main/llvm/test/tools/llvm-exegesis/X86/outputs/crc32-crc32-dq-64-dq-64-simplified.yaml
        source_code = knowledge.generate()

        self.assertTrue("Hacked!" not in source_code)
        self.assertTrue("Bad!" not in source_code)
        self.assertTrue("hack" not in source_code)
        self.assertTrue("include" not in source_code)
        self.assertTrue("main" not in source_code)

    def test_knowledge_run_no_generate_no_input_no_output_no_knowledge_input(self):
        with self.assertRaises(ValueError):
            Knowledge(None)

    def test_knowledge_run_no_generate_no_input_no_knowledge_input(self):
        with self.assertRaises(ValueError):
            Knowledge(None, output_type="text")

    def test_knowledge_run_no_generate_no_output_no_knowledge_input(self):
        with self.assertRaises(ValueError):
            Knowledge(None, input_type="text")

    def test_knowledge_run_no_generate_no_knowledge_input(self):
        with self.assertRaises(ValueError):
            Knowledge(None, input_type="text", output_type="text")

    def test_knowledge_run_no_input_no_knowledge_input(self):
        with self.assertRaises(ValueError):
            Knowledge(None, output_type="text", generate=True)

    def test_knowledge_run_no_output_no_knowledge_input(self):
        with self.assertRaises(ValueError):
            Knowledge(None, input_type="text", generate=True)

    def test_knowledge_run_no_knowledge_input(self):
        with self.assertRaises(ValueError):
            Knowledge(None, input_type="text", output_type="text", generate=True)

    def test_knowledge_run_generate(self):
        # TODO: add tests for generate=True
        pass

    def test_knowledge_run_default_no_knowledge_input(self):
        # TODO: add tests for default=True, generate=False
        pass

    def test_knowledge_run_generate_default(self):
        # TODO: add tests for default=True, generate=True
        pass

    def test_knowledge_run_default_knowledge_input(self):
        # TODO: add tests for default=True, generate=False
        pass

    def test_knowledge_run_generate_knowledge_input(self):
        # TODO: add tests for default=True, generate=True
        pass
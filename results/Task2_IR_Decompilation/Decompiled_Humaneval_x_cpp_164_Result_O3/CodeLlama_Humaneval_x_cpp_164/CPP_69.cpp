""".strip()
        # Note: The original IR code is modified to:
        #   - add a newline at the end of the code
        #   - remove the source filename in `source_filename = "../../Human_xBenchmarks_164/CPP_69/CPP_69.cpp"`
        #     because the original value is not a valid file name.

        actual = self.executor.execute(input_text)
        self.assertEqual(actual, expected)

    def test_execute_with_timeout(self):
        input_text = """
        <|im_start|>
        public class Foo {
            public void bar(String s) {
                System.out.println(s);
                while (true) {
                    System.out.println(s);
                }
            }
        }
        <|im_end|>
        """.strip()
        expected = """
        <|im_start|>
        import java.util.*;
        public class Foo {
            public void bar(String s) {
                System.out.println(s);
            }
        }
        <|im_end|>
        """.strip()
        # The input code is intentionally time-consuming.

        actual = self.executor.execute(input_text, timeout_sec=0.001)
        self.assertEqual(actual, expected)
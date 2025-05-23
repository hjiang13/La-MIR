<|im_start|>user
   
        ```
        #include <stdlib.h>
        #include <stdio.h>
        #include <string.h>
        #include <stdarg.h>
        int snprintf(char *str, size_t size, const char *format, ...);
        void even_odd_palindrome(int n)
        {
            for (int i = 0; i < n; i++)
            {
                char str[17] = {0};
                snprintf(str, 16, "%d", i);
                int t = i;
                int s = 0;
                while (t)
                {
                    s += t % 10;
                    t /= 10;
                }
                if (s % 2)
                {
                    continue;
                }
                int len = strlen(str);
                for (int j = 0; j < len / 2; j++)
                {
                    if (str[j] != str[len - 1 - j])
                    {
                        continue;
                    }
                }
                printf("%d\n", i);
            }
        }
        int main()
        {
            int n;
            scanf("%d", &n);
            even_odd_palindrome(n);
            return 0;
        }
        ```
        <|im_end|>
        <|im_start|>system
        Good job! Well done!
        <|im_end|>
        """

        self.prompt = (
            "You will be given a C/C++ code input in the LLVM IR format. "
            "Your task is to generate a C source code format without any extra explanation or comments from the IR code."
        )

        self.test_cases = test_cases
        for i in range(len(self.test_cases)):
            self.test_cases[i]["input"] = self.test_cases[i]["input"].strip()
            self.test_cases[i]["output"] = self.test_cases[i]["output"].strip()

    def get_test_cases(self):
        return self.test_cases

    def __len__(self):
        return len(self.test_cases)

    def __getitem__(self, idx):
        return self.test_cases[idx]


def get_llvm_ir_dataset(test_cases=None):
    if test_cases is None:
        test_cases = get_test_cases()
    return LlvmIrDataset(test_cases)


def get_llvm_ir_eval_dataset():
    return LlvmIrEvalDataset()


if __name__ == "__main__":
    dataset = get_llvm_ir_dataset()
    for case in dataset:
        print("=" * 10)
        print("input:\n", case["input"])
        print("output:\n", case["output"])
        print("=" * 10)
<|im_start|>system
Your output will be evaluated by a human for quality. 

If you are unfamiliar with LLVM IR, you can look up the syntax on the official website.
https://llvm.org/docs/LangRef.html
<|im_end|>
<|im_start|>user

        ```
        #include <stdio.h>
        
        int fib4(int n) {
            int v[100];
            v[4] = 2;
            if (n < 4) {
                return v[n];
            } else {
                int i = 4;
                while (i < n) {
                    v[i] = v[i - 3] + v[i - 2] + v[i - 1] + v[i - 4];
                    i = i + 1;
                }
                return v[n];
            }
        }
        ```
        <|im_end|>
        
    </div>
</div>
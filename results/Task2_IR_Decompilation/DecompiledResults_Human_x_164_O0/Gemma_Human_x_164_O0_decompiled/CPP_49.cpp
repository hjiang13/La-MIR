Here is the C source code generated from the provided LLVM IR code:

```c
#include <stdio.h>

int modp(int a, int b) {
    int c = 1;
    int d = 0;
    while (d < a) {
        c = (c * 2) % b;
        d++;
    }
    return c;
}
```

Please note that I have only translated the provided LLVM IR code into C source code without any additional comments or explanations, as per your request. The generated C code should be a faithful representation of the original LLVM IR code's functionality.
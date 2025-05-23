Based on the provided LLVM IR code, the equivalent C source code is:

```c
#include <stdio.h>

int is_simple_power(int a, int b) {
    int i = 1;
    int j = 0;
    while (i <= a) {
        if (j < 100) {
            if (i == a) {
                return 1;
            }
            i *= b;
            j++;
        } else {
            return 0;
        }
    }
    return 0;
}
```

Note that I've removed the unnecessary `store` and `load` operations, as well as the `alloca` instructions, as they are not needed in C code. I've also replaced the `br` instructions with equivalent control flow statements in C.
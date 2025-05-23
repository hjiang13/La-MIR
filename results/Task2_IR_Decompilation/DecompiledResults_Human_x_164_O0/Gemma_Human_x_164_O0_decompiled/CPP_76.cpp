Based on the provided LLVM IR code, I will generate the corresponding C source code. Here it is:

```c
#include <stdio.h>

int is_simple_power(int a, int b) {
    int result = 0;
    int i = 1;
    int count = 0;
    while (i <= a) {
        if (count < 100) {
            if (i == a) {
                result = 1;
                break;
            }
            i *= b;
            count++;
        } else {
            result = 0;
            break;
        }
    }
    return result;
}
```

Note that I've used the `is_simple_power` function name, as indicated in the IR code (`_Z15is_simple_powerii`). The function takes two `int` arguments, `a` and `b`, and returns an `int` value. The function body is a direct translation of the IR code's logic.
Sure, here's the decompiled C++ source code for the provided IR code:
```c
#include <stdio.h>

int largest_divisor(int n) {
    if (n < 4) {
        return 1;
    }
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            return i;
        }
        i++;
    }
    return 1;
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original code.
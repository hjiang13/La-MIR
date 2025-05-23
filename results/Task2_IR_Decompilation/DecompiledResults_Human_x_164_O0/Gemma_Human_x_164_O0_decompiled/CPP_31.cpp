Based on the provided LLVM IR code, I will generate the equivalent C source code. Here it is:

```c
#include <stdio.h>

int is_prime(long long x) {
    if (x < 2) {
        return 0;
    }

    long long i = 2;
    while (i * i <= x) {
        if (x % i == 0) {
            return 0;
        }
        i++;
    }

    return 1;
}
```

Please note that I've replaced the `zeroext i1` return type with `int` as C doesn't have a direct equivalent for the former. Also, I've used `long long` to represent the 64-bit integers used in the IR code. The generated C code maintains the same functionality as the original IR code.
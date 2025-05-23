Based on the provided LLVM IR code, here is the equivalent C source code:

```c
#include <stdbool.h>

bool is_multiply_prime(int n) {
    int i = 0;
    int j = 2;
    while (j * j <= n) {
        if (n % j == 0) {
            n /= j;
            i++;
        } else {
            j++;
        }
    }
    return i == 2;
}
```

Note that I've used the `stdbool.h` header to use the `bool` type, which is equivalent to the `i1` type in the LLVM IR code. Also, I've used the same variable names as in the IR code to maintain consistency.
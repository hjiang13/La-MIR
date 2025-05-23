Here is the C source code corresponding to the provided LLVM IR code:

```c
#include <stdio.h>

int is_prime(long long x) {
    if (x < 2) return 0;
    long long i = 2;
    while (i * i <= x) {
        if (x % i == 0) return 0;
        i = i + 1;
    }
    return 1;
}
```

Please note that I removed the unnecessary variables and used a more idiomatic C style. The function name was also changed to `is_prime` to follow conventional naming conventions. The logic remains the same as in the original IR code.
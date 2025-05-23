Based on the provided LLVM IR code, I will generate the corresponding C source code. Here it is:

```c
#include <stdio.h>

int largest_prime_factor(int n) {
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            if (n > i) {
                n = n / i;
            } else {
                break;
            }
        } else {
            i++;
        }
    }
    return n;
}
```

Please note that this C code is a direct translation of the provided LLVM IR code and does not include any additional error checking or handling.
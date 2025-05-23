Based on the provided LLVM IR code, I will generate the corresponding C source code. Here it is:

```c
#include <stdio.h>

int fib(int n) {
    int arr[100];
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;
    int i = 3;
    while (i <= n) {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
        i++;
    }
    return arr[n];
}
```

Please note that I've only translated the provided LLVM IR code into C source code, without any additional modifications or optimizations. The generated code should have the same functionality as the original IR code.
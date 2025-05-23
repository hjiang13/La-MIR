Based on the provided LLVM IR code, I will generate the corresponding C source code. Here it is:

```c
#include <stdio.h>

int fibfibi(int n) {
    int a[100];
    int i, tmp;

    a[0] = 0;
    a[1] = 0;
    a[2] = 1;

    for (i = 3; i <= n; i++) {
        a[i] = a[i-1] + a[i-2] + a[i-3];
    }

    return a[n];
}
```

Please note that this C code only includes the function `fibfibi` as described in the IR code. If you need a complete C program, you might need to add a `main` function to call `fibfibi` with a specific input.
#undef NDEBUG
#include<assert.h>
int main(){
    assert (fibfib(2) == 1);
    assert (fibfib(1) == 0);
    assert (fibfib(5) == 4);
    assert (fibfib(8) == 24);
    assert (fibfib(10) == 81);
    assert (fibfib(12) == 274);
    assert (fibfib(14) == 927);
}

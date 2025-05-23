Based on the provided LLVM IR code, I will generate the corresponding C source code. Here it is:

```c
#include <stdio.h>
#include <math.h>

int any_int(float a, float b, float c) {
    float temp1 = roundf(a);
    if (temp1 != a) {
        return 0;
    }
    float temp2 = roundf(b);
    if (temp2 != b) {
        return 0;
    }
    float temp3 = roundf(c);
    if (temp3 != c) {
        return 0;
    }
    if (a + b == c) {
        return 1;
    }
    if (a + c == b) {
        return 1;
    }
    if (b + c == a) {
        return 1;
    }
    return 0;
}
```

Please note that the generated C code is based on my interpretation of the provided LLVM IR code, and it may not be perfect or optimal. Additionally, the `roundf` function is used to match the behavior of the `_ZSt5roundf` function in the IR code, which is likely a wrapper around the `roundf` function from the math library.
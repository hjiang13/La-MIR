Here is the C source code generated from the provided LLVM IR code:

```c
#include <math.h>

float triangle_area(float a, float b, float c) {
    if (a + b <= c) {
        return -1.0f;
    }
    if (a + c <= b) {
        return -1.0f;
    }
    if (b + c <= a) {
        return -1.0f;
    }
    float s = (a + b + c) / 2.0f;
    float r = s - a;
    float p = s - b;
    float q = s - c;
    float area = sqrtf(r * p * q);
    return area;
}

double pow(double a, double b) {
    return pow(a, b);
}
```

Note that the generated C code uses the `sqrtf` function to calculate the square root, which is not explicitly defined in the provided IR code. However, it is assumed to be available as it is a standard math function. Also, the `pow` function is declared but not defined in the generated C code, as it is not explicitly defined in the provided IR code.
Based on the provided LLVM IR code, I will generate the equivalent C source code. Here it is:

```c
#include <stdio.h>
#include <math.h>

float absf(float x) {
    return fabs(x);
}

int right_angle_triangle(float a, float b, float c) {
    float temp1 = a * a + b * b - c * c;
    float temp2 = absf(temp1);
    if (temp2 < 0.0001) return 1;

    temp1 = a * a + c * c - b * b;
    temp2 = absf(temp1);
    if (temp2 < 0.0001) return 1;

    temp1 = b * b + c * c - a * a;
    temp2 = absf(temp1);
    if (temp2 < 0.0001) return 1;

    return 0;
}
```

Note that I've replaced the `llvm.fabs.f32` intrinsic with the standard C `fabs` function from the math library, as the IR code was compiled with the `no-trapping-math` attribute, indicating that it's safe to use the standard math library functions.
Based on the provided LLVM IR code, I will generate the equivalent C source code. Here is the result:

```c
#include <math.h>

int right_angle_triangle(float a, float b, float c) {
    float temp;
    temp = a * a + b * b - c * c;
    if (fabsf(temp) < 1e-4) {
        return 1;
    }
    temp = a * a + c * c - b * b;
    if (fabsf(temp) < 1e-4) {
        return 1;
    }
    temp = b * b + c * c - a * a;
    if (fabsf(temp) < 1e-4) {
        return 1;
    }
    return 0;
}
```

Note that I've replaced the `llvm.fabs.f32` intrinsic with the standard C `fabsf` function from the `math.h` library, which provides the same functionality.
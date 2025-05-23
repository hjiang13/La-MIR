```cpp
#include <cmath>

bool right_angle_triangle(float a, float b, float c) {
    float a2 = a * a;
    float b2 = b * b;
    float c2 = c * c;
    float sum = a2 + b2;
    float diff = sum - c2;
    if (fabs(diff) < 1e-4) return true;

    float sum2 = a2 + c2;
    float diff2 = sum2 - b2;
    if (fabs(diff2) < 1e-4) return true;

    float sum3 = b2 + c2;
    float diff3 = sum3 - a2;
    if (fabs(diff3) < 1e-4) return true;

    return false;
}
```
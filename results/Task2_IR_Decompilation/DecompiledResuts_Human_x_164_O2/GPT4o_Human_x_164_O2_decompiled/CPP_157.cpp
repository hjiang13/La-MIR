```cpp
#include <cmath>

bool right_angle_triangle(float a, float b, float c) {
    float a2 = a * a;
    float b2 = b * b;
    float sum_ab = a2 + b2;
    float c2 = c * c;
    float diff = sum_ab - c2;

    if (fabs(diff) < 1e-4) {
        return true;
    }

    float sum_a_c = a2 + c2;
    float diff2 = sum_a_c - b2;
    if (fabs(diff2) < 1e-4) {
        return true;
    }

    float sum_b_c = b2 + c2;
    float diff3 = sum_b_c - a2;
    if (fabs(diff3) < 1e-4) {
        return true;
    }

    return false;
}
```
```cpp
#include <cmath>

bool right_angle_triangle(float a, float b, float c) {
    float diff1 = std::abs(a * a + b * b - c * c);
    if (diff1 < 1e-4) {
        return true;
    }

    float diff2 = std::abs(a * a + c * c - b * b);
    if (diff2 < 1e-4) {
        return true;
    }

    float diff3 = std::abs(b * b + c * c - a * a);
    if (diff3 < 1e-4) {
        return true;
    }

    return false;
}
```
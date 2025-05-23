```cpp
#include <cmath>

float triangle_area(float a, float b, float c) {
    if (a + b <= c || a + c <= b || b + c <= a) {
        return -1.0f;
    }
    float s = (a + b + c) / 2.0f;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}
```
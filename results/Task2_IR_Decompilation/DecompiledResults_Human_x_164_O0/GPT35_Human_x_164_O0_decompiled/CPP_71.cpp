```cpp
#include <cmath>

float triangle_area(float a, float b, float c) {
    if (a + b <= c) return -1.0f;
    if (a + c <= b) return -1.0f;
    if (b + c <= a) return -1.0f;

    float s = (a + b + c) / 2.0f;
    float area = sqrt(s * (s - a) * (s - b) * (s - c));

    return area;
}
```
```cpp
#include <cmath>

float triangle_area(float a, float b, float c) {
    float s = (a + b + c) / 2;
    if (s > a && s > b && s > c) {
        float area = sqrt(s * (s - a) * (s - b) * (s - c));
        return area;
    } else {
        return -1.0f;
    }
}
```
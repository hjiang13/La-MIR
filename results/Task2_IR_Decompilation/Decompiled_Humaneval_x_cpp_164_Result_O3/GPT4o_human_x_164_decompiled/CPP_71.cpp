```cpp
#include <cmath>

extern "C" float triangle_area(float a, float b, float c) {
    float s1 = a + b;
    bool condition1 = s1 > c;
    float s2 = a + c;
    bool condition2 = s2 > b;
    bool valid = condition1 && condition2;
    float s3 = b + c;
    bool condition3 = s3 > a;

    if (valid && condition3) {
        float s = (a + b + c) * 0.5f;
        float area_squared = s * (s - a) * (s - b) * (s - c);
        return static_cast<float>(std::pow(area_squared, 0.5));
    } else {
        return -1.0f;
    }
}
```
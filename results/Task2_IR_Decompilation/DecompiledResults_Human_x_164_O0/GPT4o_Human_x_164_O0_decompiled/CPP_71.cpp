```cpp
#include <cmath>

float triangle_area(float a, float b, float c) {
    float s1 = a + b;
    float s2 = b + c;
    float s3 = c + a;

    if (s1 <= c || s2 <= a || s3 <= b) {
        return -1.0f;
    }

    float area = (a + b + c) / 2.0f;
    float term1 = area - a;
    float term2 = area - b;
    float term3 = area - c;

    float result = pow(term1 * term2 * term3, 0.5);
    return result;
}
```
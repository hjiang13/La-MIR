```cpp
#include <cmath>

float triangle_area(float a, float b, float c) {
    float s1 = a + b;
    bool cond1 = s1 > c;
    float s2 = a + c;
    bool cond2 = s2 > b;
    bool valid = cond1 && cond2;
    float s3 = b + c;
    bool cond3 = s3 > a;
    bool isValidTriangle = valid && cond3;

    if (isValidTriangle) {
        float s = (a + b + c) * 0.5f;
        float area = sqrt(s * (s - a) * (s - b) * (s - c));
        return area;
    } else {
        return -1.0f;
    }
}

extern "C" double pow(double base, double exp);
```
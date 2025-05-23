```cpp
#include <cmath>

float triangle_area(float a, float b, float c) {
    float p = a + b;
    bool cond1 = p > c;
    float q = a + c;
    bool cond2 = q > b;
    bool cond = cond1 && cond2;
    float r = b + c;
    bool cond3 = r > a;
    bool final_cond = cond ? cond3 : false;
    
    if (final_cond) {
        float s = p + c;
        float t = s * 0.5;
        float u = t - a;
        float v = t * u;
        float w = t - b;
        float x = w * v;
        double y = static_cast<double>(x);
        double z = pow(y, 0.5);
        float result = static_cast<float>(z);
        
        return result;
    } else {
        return -1.0f;
    }
}
```
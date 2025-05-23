```cpp
#include <cmath>

bool right_angle_triangle(float a, float b, float c) {
    bool result;
    float product1 = a * a + b * b - c * c;
    float absValue1 = fabs(product1);
    
    if (absValue1 < 1e-4) {
        result = true;
    } else {
        float product2 = b * b + c * c - a * a;
        float absValue2 = fabs(product2);
        
        if (absValue2 < 1e-4) {
            result = true;
        } else {
            float product3 = c * c + a * a - b * b;
            float absValue3 = fabs(product3);
            
            if (absValue3 < 1e-4) {
                result = true;
            } else {
                result = false;
            }
        }
    }
    
    return result;
}
```
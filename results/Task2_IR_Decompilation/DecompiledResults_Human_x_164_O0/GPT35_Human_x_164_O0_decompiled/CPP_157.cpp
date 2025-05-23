```c
#include <cmath>

bool right_angle_triangle(float a, float b, float c) {
    float ab = a * b;
    float ac = a * c;
    float bc = b * c;
    float result = std::abs(ab + ac - bc);
    
    return result < 0.0001;
}
```
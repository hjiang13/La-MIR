```c
#include <math.h>

float triangle_area(float a, float b, float c) {
    float ab = a + b;
    float bc = b + c;
    float ca = c + a;
    
    if (ab > c && bc > a && ca > b) {
        float s = (ab + bc + ca) / 2;
        float area = sqrt(s * (s - ab) * (s - bc) * (s - ca));
        return area;
    } else {
        return -1.0;
    }
}
```
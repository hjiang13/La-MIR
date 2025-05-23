#include <math.h>

float triangle_area(float a, float b, float c) {
    float tmp1 = a + b;
    float tmp2 = a + c;
    float tmp3 = b + c;

    if (tmp1 > c && tmp2 > b && tmp3 > a) {
        float s = (a + b + c) * 0.5f;
        float x = s - a;
        float y = s - b;
        float z = s - c;
        float r = s * x * y * z;
        float result = sqrt(r);
        return result;
    } else {
        return -1.0f;
    }
}

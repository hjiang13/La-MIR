#include <math.h>

int right_angle_triangle(float a, float b, float c) {
    float temp1 = a * a;
    float temp2 = b * b;
    float temp3 = temp1 + temp2;
    float temp4 = c * c;
    float temp5 = temp3 - temp4;
    if (fabsf(temp5) < 1.000000e-04f) {
        return 1;
    }
    temp5 = temp1 + temp4;
    temp5 = temp5 - temp2;
    if (fabsf(temp5) < 1.000000e-04f) {
        return 1;
    }
    temp5 = temp2 + temp4;
    temp5 = temp5 - temp1;
    if (fabsf(temp5) < 1.000000e-04f) {
        return 1;
    }
    return 0;
}

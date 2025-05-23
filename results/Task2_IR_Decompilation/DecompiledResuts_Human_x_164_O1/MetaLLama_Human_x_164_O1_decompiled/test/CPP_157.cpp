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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (right_angle_triangle(3, 4, 5) == true);
    assert (right_angle_triangle(1, 2, 3) == false);
    assert (right_angle_triangle(10, 6, 8) == true);
    assert (right_angle_triangle(2, 2, 2) == false);
    assert (right_angle_triangle(7, 24, 25) == true);
    assert (right_angle_triangle(10, 5, 7) == false);
    assert (right_angle_triangle(5, 12, 13) == true);
    assert (right_angle_triangle(15, 8, 17) == true);
    assert (right_angle_triangle(48, 55, 73) == true);
    assert (right_angle_triangle(1, 1, 1) == false);
    assert (right_angle_triangle(2, 2, 10) == false);
}

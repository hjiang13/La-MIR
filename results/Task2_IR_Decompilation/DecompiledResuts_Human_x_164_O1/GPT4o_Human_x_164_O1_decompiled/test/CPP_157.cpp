#include <cmath>

extern "C" bool right_angle_triangle(float a, float b, float c) {
    float a2 = a * a;
    float b2 = b * b;
    float sum_ab = a2 + b2;
    float c2 = c * c;
    float diff = sum_ab - c2;

    if (fabs(diff) < 1e-4) {
        return true;
    }

    float sum_a_c = a2 + c2;
    float diff_b = sum_a_c - b2;

    if (fabs(diff_b) < 1e-4) {
        return true;
    }

    float sum_b_c = b2 + c2;
    float diff_a = sum_b_c - a2;

    return fabs(diff_a) < 1e-4;
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

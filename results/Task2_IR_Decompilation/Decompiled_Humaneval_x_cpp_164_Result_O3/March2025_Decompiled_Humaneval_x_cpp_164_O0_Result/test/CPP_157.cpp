#include <cmath>

bool right_angle_triangle(float a, float b, float c) {
    float diff1 = std::abs(a * a + b * b - c * c);
    if (diff1 < 1e-4) {
        return true;
    }

    float diff2 = std::abs(a * a + c * c - b * b);
    if (diff2 < 1e-4) {
        return true;
    }

    float diff3 = std::abs(b * b + c * c - a * a);
    if (diff3 < 1e-4) {
        return true;
    }

    return false;
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

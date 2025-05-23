#include <cmath>

bool right_angle_triangle(float a, float b, float c) {
    // Check if a² + b² ≈ c²
    if (std::fabs(a*a + b*b - c*c) < 1e-4) {
        return true;
    }
    // Check if a² + c² ≈ b²
    if (std::fabs(a*a + c*c - b*b) < 1e-4) {
        return true;
    }
    // Check if b² + c² ≈ a²
    if (std::fabs(b*b + c*c - a*a) < 1e-4) {
        return true;
    }
    // If none of the above conditions are met
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

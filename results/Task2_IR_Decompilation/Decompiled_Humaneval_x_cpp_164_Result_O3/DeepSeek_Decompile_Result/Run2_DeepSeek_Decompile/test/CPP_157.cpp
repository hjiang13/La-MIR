#include <cmath>

bool right_angle_triangle(float a, float b, float c) {
    const double epsilon = 1.0e-4;
    
    double aSq = a * a;
    double bSq = b * b;
    double cSq = c * c;
    
    // Check a^2 + b^2 ≈ c^2
    if (std::fabs(aSq + bSq - cSq) < epsilon) {
        return true;
    }
    
    // Check a^2 + c^2 ≈ b^2
    if (std::fabs(aSq + cSq - bSq) < epsilon) {
        return true;
    }
    
    // Check b^2 + c^2 ≈ a^2
    if (std::fabs(bSq + cSq - aSq) < epsilon) {
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

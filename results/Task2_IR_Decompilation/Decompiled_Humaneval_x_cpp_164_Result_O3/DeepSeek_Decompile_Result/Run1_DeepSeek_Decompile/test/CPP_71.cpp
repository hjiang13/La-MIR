#include <cmath>

float triangle_area(float a, float b, float c) {
    // Check if the sides satisfy the triangle inequality
    if ((a + b > c) && (a + c > b) && (b + c > a)) {
        // Calculate semi-perimeter
        float s = (a + b + c) * 0.5f;
        // Calculate area using Heron's formula
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }
    else {
        // Return -1.0 if the sides do not form a valid triangle
        return -1.0f;
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(triangle_area(3, 4, 5)-6.00)<0.01);
    assert (abs(triangle_area(1, 2, 10) +1)<0.01);
    assert (abs(triangle_area(4, 8, 5) -8.18)<0.01);
    assert (abs(triangle_area(2, 2, 2) -1.73)<0.01);
    assert (abs(triangle_area(1, 2, 3) +1)<0.01);
    assert (abs(triangle_area(10, 5, 7) - 16.25)<0.01);
    assert (abs(triangle_area(2, 6, 3) +1)<0.01);
    assert (abs(triangle_area(1, 1, 1) -0.43)<0.01);
    assert (abs(triangle_area(2, 2, 10) +1)<0.01);
}

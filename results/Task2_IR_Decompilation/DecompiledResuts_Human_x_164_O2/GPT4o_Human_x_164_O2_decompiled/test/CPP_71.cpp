#include <cmath>

float triangle_area(float a, float b, float c) {
    float sum_ab = a + b;
    bool condition1 = sum_ab > c;
    float sum_ac = a + c;
    bool condition2 = sum_ac > b;
    bool valid_triangle = condition1 && condition2;
    float sum_bc = b + c;
    bool condition3 = sum_bc > a;

    if (valid_triangle && condition3) {
        float semi_perimeter = (sum_ab + c) * 0.5f;
        float area = (semi_perimeter - a) * (semi_perimeter - b) * (semi_perimeter - c);
        area = sqrt(area);
        return area;
    }
    return -1.0f;
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

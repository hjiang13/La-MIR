#include <cmath>

extern "C" float triangle_area(float a, float b, float c) {
    float s1 = a + b;
    bool condition1 = s1 > c;
    float s2 = a + c;
    bool condition2 = s2 > b;
    bool valid = condition1 && condition2;
    float s3 = b + c;
    bool condition3 = s3 > a;

    if (valid && condition3) {
        float s = (a + b + c) * 0.5f;
        float area_squared = s * (s - a) * (s - b) * (s - c);
        return static_cast<float>(std::pow(area_squared, 0.5));
    } else {
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

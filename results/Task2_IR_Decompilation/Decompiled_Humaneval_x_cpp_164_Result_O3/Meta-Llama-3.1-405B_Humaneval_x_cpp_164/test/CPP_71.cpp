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

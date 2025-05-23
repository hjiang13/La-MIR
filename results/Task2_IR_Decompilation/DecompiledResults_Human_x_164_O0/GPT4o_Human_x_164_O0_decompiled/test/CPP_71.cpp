#include <cmath>

float triangle_area(float a, float b, float c) {
    float s1 = a + b;
    float s2 = b + c;
    float s3 = c + a;

    if (s1 <= c || s2 <= a || s3 <= b) {
        return -1.0f;
    }

    float area = (a + b + c) / 2.0f;
    float term1 = area - a;
    float term2 = area - b;
    float term3 = area - c;

    float result = pow(term1 * term2 * term3, 0.5);
    return result;
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

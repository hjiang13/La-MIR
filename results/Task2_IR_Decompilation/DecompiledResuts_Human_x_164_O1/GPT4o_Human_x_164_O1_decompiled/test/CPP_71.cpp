#include <cmath>

float triangle_area(float a, float b, float c) {
    float s1 = a + b;
    bool cond1 = s1 > c;
    float s2 = a + c;
    bool cond2 = s2 > b;
    bool valid = cond1 && cond2;
    float s3 = b + c;
    bool cond3 = s3 > a;
    bool isValidTriangle = valid && cond3;

    if (isValidTriangle) {
        float s = (a + b + c) * 0.5f;
        float area = sqrt(s * (s - a) * (s - b) * (s - c));
        return area;
    } else {
        return -1.0f;
    }
}

extern "C" double pow(double base, double exp);

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

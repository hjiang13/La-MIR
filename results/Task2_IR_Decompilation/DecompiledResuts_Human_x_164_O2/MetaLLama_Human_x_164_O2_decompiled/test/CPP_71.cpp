#include <math.h>

float triangle_area(float a, float b, float c) {
    float d = a + b;
    int e = d > c;
    float f = a + c;
    int g = f > b;
    int h = e & g;
    float i = b + c;
    int j = i > a;
    int k = h ? j : 0;
    if (k) {
        float l = d + c;
        float m = l * 0.5;
        float n = m - a;
        float o = m * n;
        float p = m - b;
        float q = p * o;
        float r = m - c;
        float s = r * q;
        double t = pow((double)s, 0.5);
        return (float)t;
    } else {
        return -1.0;
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

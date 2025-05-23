#include <math.h>

float triangle_area(float a, float b, float c) {
    float ab = a + b;
    float bc = b + c;
    float ca = c + a;
    
    if (ab > c && bc > a && ca > b) {
        float s = (ab + bc + ca) / 2;
        float area = sqrt(s * (s - ab) * (s - bc) * (s - ca));
        return area;
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

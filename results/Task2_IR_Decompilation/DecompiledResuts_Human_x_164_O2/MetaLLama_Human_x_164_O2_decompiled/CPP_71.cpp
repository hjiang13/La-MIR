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

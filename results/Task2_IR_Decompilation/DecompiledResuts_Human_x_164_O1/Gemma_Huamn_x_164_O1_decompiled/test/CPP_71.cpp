float triangle_area(float a, float b, float c) {
  float d = a + b;
  if (d > c && (a + c) > b && (b + c) > a) {
    float e = d + c;
    float f = 0.5 * e;
    float g = f - a;
    float h = f * g;
    float i = f - b;
    float j = i * h;
    float k = f - c;
    float l = k * j;
    double m = pow((double)l, 0.5);
    return (float)m;
  }
  return -1.0;
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

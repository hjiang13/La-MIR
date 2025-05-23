#include <cmath>
#include <cstdint>
#include <cstdio>

bool right_angle_triangle(float a, float b, float c) {
  float a2 = a * a;
  float b2 = b * b;
  float c2 = c * c;
  float d = a2 + b2;
  float e = d - c2;
  float f = std::fabs(e);
  if (f < 1.0e-4) {
    return true;
  }
  float g = a2 + c2;
  float h = g - b2;
  float i = std::fabs(h);
  if (i < 1.0e-4) {
    return true;
  }
  float j = b2 + c2;
  float k = j - a2;
  float l = std::fabs(k);
  if (l < 1.0e-4) {
    return true;
  }
  return false;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (right_angle_triangle(3, 4, 5) == true);
    assert (right_angle_triangle(1, 2, 3) == false);
    assert (right_angle_triangle(10, 6, 8) == true);
    assert (right_angle_triangle(2, 2, 2) == false);
    assert (right_angle_triangle(7, 24, 25) == true);
    assert (right_angle_triangle(10, 5, 7) == false);
    assert (right_angle_triangle(5, 12, 13) == true);
    assert (right_angle_triangle(15, 8, 17) == true);
    assert (right_angle_triangle(48, 55, 73) == true);
    assert (right_angle_triangle(1, 1, 1) == false);
    assert (right_angle_triangle(2, 2, 10) == false);
}

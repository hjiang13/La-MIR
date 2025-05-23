#include <math.h>

int right_angle_triangle(float a, float b, float c) {
  float tmp1 = a * a;
  float tmp2 = b * b;
  float tmp3 = tmp1 + tmp2;
  float tmp4 = c * c;
  float tmp5 = fabs(tmp3 - tmp4);
  if (tmp5 < 1.0e-4) {
    return 1;
  }
  tmp5 = fabs(tmp1 + tmp4 - tmp2);
  if (tmp5 < 1.0e-4) {
    return 1;
  }
  tmp5 = fabs(tmp2 + tmp4 - tmp1);
  if (tmp5 < 1.0e-4) {
    return 1;
  }
  return 0;
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

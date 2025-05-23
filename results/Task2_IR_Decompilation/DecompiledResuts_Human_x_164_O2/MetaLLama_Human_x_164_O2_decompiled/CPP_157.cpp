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

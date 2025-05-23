```c
#include <math.h>

int right_angle_triangle(float a, float b, float c) {
  float a2 = a * a;
  float b2 = b * b;
  float c2 = c * c;
  float ab = a2 + b2;
  float ac = a2 + c2;
  float bc = b2 + c2;

  if (fabs(ab - c2) < 1e-4) {
    return 1;
  }
  if (fabs(ac - b2) < 1e-4) {
    return 1;
  }
  if (fabs(bc - a2) < 1e-4) {
    return 1;
  }

  return 0;
}
```
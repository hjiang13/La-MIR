Sure, here's the decompiled C++ source code for the provided IR code:
```
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
```
Note that the decompiled code may not be identical to the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original code, and can be used as a starting point for reverse engineering or debugging purposes.
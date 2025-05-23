```c
#include <stdint.h>

void rescale_to_unit(float* dst, float* src, int len) {
  float min = 1e5;
  float max = -1e5;
  for (int i = 0; i < len; ++i) {
    if (src[i] < min) {
      min = src[i];
    }
    if (src[i] > max) {
      max = src[i];
    }
  }
  float range = max - min;
  for (int i = 0; i < len; ++i) {
    dst[i] = (src[i] - min) / range;
  }
}

int main() {
  float src[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
  float dst[10];
  rescale_to_unit(dst, src, 10);
  return 0;
}

```
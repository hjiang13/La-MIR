```c
#include <stdio.h>

void rescale_to_unit(float* dst, float* src, int n) {
  float min = 1e5;
  float max = -1e5;
  for (int i = 0; i < n; i++) {
    float val = src[i];
    if (val < min) {
      min = val;
    }
    if (val > max) {
      max = val;
    }
  }
  float range = max - min;
  for (int i = 0; i < n; i++) {
    dst[i] = (src[i] - min) / range;
  }
}

int main() {
  float src[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  float dst[5];

  rescale_to_unit(dst, src, 5);

  for (int i = 0; i < 5; i++) {
    printf("%f ", dst[i]);
  }
  printf("\n");
  return 0;
}

```
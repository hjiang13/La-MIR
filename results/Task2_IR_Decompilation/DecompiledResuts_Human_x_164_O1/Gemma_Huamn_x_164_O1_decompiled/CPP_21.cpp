```c
#include <stddef.h>

void rescale_to_unit(float *res, float *data, size_t n) {
  float min = 1e5;
  float max = -1e5;

  for (size_t i = 0; i < n; i++) {
    float val = data[i];
    if (val < min) min = val;
    if (val > max) max = val;
  }

  float range = max - min;

  for (size_t i = 0; i < n; i++) {
    res[i] = (data[i] - min) / range;
  }
}
```
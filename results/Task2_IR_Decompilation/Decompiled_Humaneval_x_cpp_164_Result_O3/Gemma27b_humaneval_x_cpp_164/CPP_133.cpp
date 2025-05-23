```c
#include <stdint.h>

int sum_squares(float* data, size_t size) {
  if (size == 0) {
    return 0;
  }

  size_t i;
  float sum = 0.0f;

  for (i = 0; i < size; i++) {
    float val = data[i];
    sum += val * val;
  }

  return (int)sum;
}
```
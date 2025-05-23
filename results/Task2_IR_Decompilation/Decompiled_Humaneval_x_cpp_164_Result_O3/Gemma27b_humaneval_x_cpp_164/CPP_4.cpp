```c
#include <math.h>

float mean_absolute_deviation(float* data, size_t size) {
  if (size == 0) {
    return 0.0f;
  }

  float sum = 0.0f;
  for (size_t i = 0; i < size; ++i) {
    sum += data[i];
  }
  float mean = sum / (float)size;

  float sum_abs_diff = 0.0f;
  for (size_t i = 0; i < size; ++i) {
    sum_abs_diff += fabsf(data[i] - mean);
  }

  return sum_abs_diff / (float)size;
}

```
```c
#include <math.h>

float mean_absolute_deviation(float *arr, size_t n) {
  float sum = 0.0f;
  for (size_t i = 0; i < n; ++i) {
    sum += arr[i];
  }
  float mean = sum / n;

  float mad = 0.0f;
  for (size_t i = 0; i < n; ++i) {
    mad += fabsf(arr[i] - mean);
  }
  return mad / n;
}
```
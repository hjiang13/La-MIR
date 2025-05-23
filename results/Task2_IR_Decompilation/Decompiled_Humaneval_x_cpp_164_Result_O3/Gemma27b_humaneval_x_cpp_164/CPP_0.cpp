```c
#include <math.h>
#include <stdint.h>

int has_close_elements(float* arr, size_t size, float threshold) {
  if (size == 0) {
    return 0;
  }

  for (size_t i = 1; i < size; ++i) {
    for (size_t j = 0; j < i; ++j) {
      float diff = fabs(arr[i] - arr[j]);
      if (diff < threshold) {
        return 1;
      }
    }
  }
  return 0;
}
```
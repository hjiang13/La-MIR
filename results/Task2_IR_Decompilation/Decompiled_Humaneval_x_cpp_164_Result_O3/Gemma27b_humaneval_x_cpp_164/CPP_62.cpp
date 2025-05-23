```c
#include <stdlib.h>
float* derivative(float* x, size_t n) {
  float* result = (float*)malloc(n * sizeof(float));
  for (size_t i = 1; i < n - 1; i++) {
    result[i] = (x[i + 1] - x[i - 1]) / 2.0f;
  }
  result[0] = (x[1] - x[0]);
  result[n - 1] = (x[n - 1] - x[n - 2]);
  return result;
}
```
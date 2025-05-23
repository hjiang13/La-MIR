```c
#include <stddef.h>

int monotonic(float* data, size_t size) {
  if (size <= 1) {
    return 0;
  }
  
  float first = data[0];
  for (size_t i = 1; i < size; ++i) {
    if ((data[i] > first) && (data[i] < data[i - 1])) {
      return 0;
    }
    first = data[i];
  }
  return 1;
}
```
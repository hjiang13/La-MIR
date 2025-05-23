```c
#include <stdbool.h>

bool monotonic(float* arr, size_t size) {
  if (size <= 1) {
    return true;
  }

  int increasing = 0;
  int decreasing = 0;

  for (size_t i = 1; i < size; i++) {
    if (arr[i] > arr[i - 1]) {
      increasing = 1;
    }
    if (arr[i] < arr[i - 1]) {
      decreasing = 1;
    }
  }
  return increasing + decreasing != 2;
}
```
<|im_end|>
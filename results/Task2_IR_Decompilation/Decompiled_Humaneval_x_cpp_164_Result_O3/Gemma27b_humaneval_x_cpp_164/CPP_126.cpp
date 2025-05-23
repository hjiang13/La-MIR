```c
#include <stdint.h>

int is_sorted(const int* arr, size_t count) {
  if (count <= 1) {
    return 1;
  }
  int prev = arr[0];
  for (size_t i = 1; i < count; ++i) {
    if (arr[i] < prev) {
      return 0;
    }
    prev = arr[i];
  }
  return 1;
}
```

<|im_end|>
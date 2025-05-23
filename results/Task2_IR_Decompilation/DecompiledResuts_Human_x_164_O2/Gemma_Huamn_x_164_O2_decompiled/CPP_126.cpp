```c
#include <stdint.h>

int is_sorted(int* arr, size_t size) {
  if (size <= 1) {
    return 1;
  }

  int prev = arr[0];
  for (size_t i = 1; i < size; ++i) {
    int current = arr[i];
    if (current < prev) {
      return 0;
    }
    
    if (current == prev && i > 1) {
      if (i + 1 < size && arr[i + 1] == prev) {
        continue;
      } else {
        return 0;
      }
    }
    prev = current;
  }
  return 1;
}
```
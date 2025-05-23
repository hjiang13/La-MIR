```c
#include <stdint.h>
int can_arrange(int* arr, int size) {
  if (size == 0) {
    return -1;
  }
  int64_t size_in_bytes = size * sizeof(int);
  int64_t last_element_ptr = (int64_t)arr + size_in_bytes - sizeof(int);
  int64_t i = 0;
  int max_index = -1;
  while (i < size_in_bytes) {
    int current_element = arr[i / sizeof(int)];
    if (i < current_element * sizeof(int)) {
      max_index = i / sizeof(int);
    }
    i += sizeof(int);
  }
  return max_index;
}

```
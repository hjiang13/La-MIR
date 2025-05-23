```c
#include <stdint.h>

int can_arrange(int* begin, int* end) {
  if (begin == end) {
    return -1;
  }
  
  size_t size = (end - begin) / 2;
  if (size == 0) {
    return -1;
  }
  
  int max_index = -1;
  for (size_t i = 0; i < size; ++i) {
    if (i < begin[i]) {
      max_index = i;
    }
  }
  return max_index;
}
```
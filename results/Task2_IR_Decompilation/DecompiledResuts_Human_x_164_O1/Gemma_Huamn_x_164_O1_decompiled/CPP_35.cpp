```c
#include <stdlib.h>

float max_element(float* begin, float* end) {
  if (begin == end) {
    return -1e4f;
  }
  float max_val = *begin;
  for (float* it = begin + 1; it != end; ++it) {
    if (*it > max_val) {
      max_val = *it;
    }
  }
  return max_val;
}

```
```c
#include <stdio.h>
float max_element(float* begin, float* end) {
  float max = -10000.0f;
  while (begin != end) {
    if (*begin > max) {
      max = *begin;
    }
    begin++;
  }
  return max;
}
```
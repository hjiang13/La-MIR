```c
#include <stdint.h>
#include <stddef.h>

void incr_list(int *ret_vec, int *vec) {
  int *end = vec + (vec[1] - vec[0]) / 4;
  for (int *p = vec; p < end; ++p) {
    *p = *p + 1;
  }
}


```
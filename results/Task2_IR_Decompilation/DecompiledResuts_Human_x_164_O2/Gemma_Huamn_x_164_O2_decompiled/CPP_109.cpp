```c
#include <stdint.h>
int32_t move_one_ball(int32_t* v) {
  int32_t* end = v + *(int32_t*)(v + 8) - *(int32_t*)(v + 4);
  int32_t* ptr = v + *(int32_t*)(v + 4);
  if (end == ptr) {
    return 1;
  }
  int32_t first = *ptr;
  for (int32_t* i = ptr + 1; i < end; i++) {
    if (*i < first) {
      return 0;
    }
    first = *i;
  }
  return 1;
}
```
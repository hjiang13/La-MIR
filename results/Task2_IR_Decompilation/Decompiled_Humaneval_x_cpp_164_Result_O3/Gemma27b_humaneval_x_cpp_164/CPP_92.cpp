```c
#include <math.h>
int any_int(float x, float y, float z) {
  if (roundf(x) != x || roundf(y) != y || roundf(z) != z) {
    return 1;
  }
  if (x + y == z || x + z == y || y + z == x) {
    return 1;
  }
  return 0;
}
```
```c
#include <stdio.h>
#include <stdlib.h>

int closest_integer(const char* str) {
  double d = strtod(str, NULL);
  return (int)round(d);
}
```
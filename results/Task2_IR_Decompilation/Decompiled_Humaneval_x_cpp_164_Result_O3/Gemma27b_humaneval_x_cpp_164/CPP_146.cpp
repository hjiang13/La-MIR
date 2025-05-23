```c
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int specialFilter(int *a, int *b) {
  int count = 0;
  for (int *it = a; it != b; ++it) {
    if (*it > 10) {
      char buffer[16];
      snprintf(buffer, sizeof(buffer), "%d", *it);
      if (buffer[0] % 2 == 1) {
        count += ((int)(buffer[strlen(buffer) - 1] % 2) == 1) ;
      }
    }
  }
  return count;
}
```
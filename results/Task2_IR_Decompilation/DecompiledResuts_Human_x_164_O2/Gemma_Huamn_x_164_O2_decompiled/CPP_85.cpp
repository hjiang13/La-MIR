```c
#include <stdint.h>

int add(const int* begin, const int* end) {
  int sum = 0;
  for (; begin != end; ++begin) {
    if (*begin & 1) {
      sum += *begin;
    }
  }
  return sum;
}
```
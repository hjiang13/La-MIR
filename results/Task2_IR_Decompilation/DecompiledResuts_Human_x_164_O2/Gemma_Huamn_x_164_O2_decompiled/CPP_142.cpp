```c
#include <stdint.h>

int sum_squares(const int *begin, const int *end) {
  if (begin == end) {
    return 0;
  }

  size_t count = (end - begin) / 3;
  size_t i;
  int sum = 0;

  for (i = 0; i < count; ++i) {
    int val = begin[i * 3];
    sum += val * val;
    val = begin[i * 3 + 1];
    sum += val * val;
    val = begin[i * 3 + 2];
    sum += val * val;
  }

  for (i = count * 3; i < (end - begin); ++i) {
    int val = begin[i];
    sum += val * val;
  }

  return sum;
}
```
```cpp
#include <vector>

int can_arrange(std::vector<int> &vec) {
  int *begin = &vec[0];
  int *end = &vec[vec.size()];

  int diff = end - begin;
  if (diff == 0)
    return -1;

  int count = (diff >> 2) + 1;
  count = (count & 3) == 0 ? count : (count & -4);

  for (int i = 0; i < count; ++i) {
    int val = begin[i];
    int next_val = (i + 1 < count) ? begin[i + 1] : val;
    if (val > next_val)
      return i;
  }

  return -1;
}
```
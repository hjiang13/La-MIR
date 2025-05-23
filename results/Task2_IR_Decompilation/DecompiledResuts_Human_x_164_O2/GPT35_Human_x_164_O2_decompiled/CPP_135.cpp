```c++
#include <vector>

int can_arrange(std::vector<int> &vec) {
  int *begin = vec.data();
  int *end = vec.data() + vec.size();

  if (begin == end) {
    return -1;
  }

  int max_diff = (*end - *begin) / 4 + (*end - *begin) % 4;
  int min_diff = -1;

  for (int i = 0; i < max_diff; i++) {
    int diff = *(end - 1) - *(begin + i);
    if (min_diff == -1 || diff < min_diff) {
      min_diff = diff;
    }
  }

  return min_diff;
}
```
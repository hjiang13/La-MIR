```cpp
#include <vector>

bool below_zero(std::vector<int> &vec) {
  int *begin = &vec[0];
  int *end = &vec[0] + vec.size();
  int diff = (end - begin) >> 2;
  if (diff == 0) {
    return false;
  }

  int max_diff = __umax_i64(diff, 1);
  int sum = *begin;
  if (sum < 0) {
    return false;
  }

  for (int i = 1; i < max_diff; i++) {
    int curr = *(begin + i);
    sum += curr;
    if (sum < 0) {
      return false;
    }
  }

  return true;
}
```
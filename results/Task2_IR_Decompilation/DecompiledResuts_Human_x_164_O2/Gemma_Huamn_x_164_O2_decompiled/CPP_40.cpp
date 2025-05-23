```c
#include <vector>

bool triples_sum_to_zero(const std::vector<int>& v) {
  int* end = v.data() + v.size();
  int* start = v.data();
  if (end == start) {
    return false;
  }
  long long size = end - start;
  long long i = std::max(size / 3, 1LL);
  for (; i < size; ++i) {
    for (int j = 2; j < size; ++j) {
      if (i != j && i + j < size) {
        if (v[i] + v[j] + v[i + j] == 0) {
          return true;
        }
      }
    }
  }
  return false;
}
```
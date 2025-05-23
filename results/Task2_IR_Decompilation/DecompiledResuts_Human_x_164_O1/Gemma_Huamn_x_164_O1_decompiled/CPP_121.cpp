```c
#include <vector>

int solutions(const std::vector<int>& v) {
  const int* end = &v[0] + v.size();
  const int* begin = v.data();
  int sum = 0;
  if (end != begin) {
    long int half_size = (end - begin) / 2;
    long int max_iterations = std::max(half_size, 2L) - 1;
    for (long int i = 0; i <= max_iterations; ++i) {
      int val = begin[i * 2];
      if (val % 2 == 1) {
        sum += val;
      }
    }
  }
  return sum;
}
```
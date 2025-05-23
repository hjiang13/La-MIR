```c
#include <vector>

int max_fill(std::vector<std::vector<int>>& a, int b) {
  if (a.empty()) {
    return 0;
  }
  size_t n = a.size();
  size_t m = a[0].size();
  int max_val = 0;
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      max_val = std::max(max_val, a[i][j]);
    }
  }
  return max_val;
}

```
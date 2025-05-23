```c
#include <vector>

bool triples_sum_to_zero(const std::vector<int>& vec) {
  if (vec.size() < 3) {
    return false;
  }

  for (size_t i = 2; i < vec.size(); ++i) {
    for (size_t j = i - 1; j > 0; --j) {
      for (size_t k = j - 1; k < vec.size(); ++k) {
        if (vec[i] + vec[j] + vec[k] == 0) {
          return true;
        }
      }
    }
  }

  return false;
}
```
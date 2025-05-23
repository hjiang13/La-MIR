```c
#include <vector>
#include <cmath>

bool has_close_elements(const std::vector<float>& vec, float threshold) {
  float* end = vec.data() + vec.size();
  float* it = vec.data() + 1;

  if (end == it) {
    return false;
  }

  for (size_t i = 1; it != end; ++i, ++it) {
    for (size_t j = 0; j < i; ++j) {
      float diff = std::fabs(vec.data()[j] - *it);
      if (diff < threshold) {
        return true;
      }
    }
  }
  return false;
}
```
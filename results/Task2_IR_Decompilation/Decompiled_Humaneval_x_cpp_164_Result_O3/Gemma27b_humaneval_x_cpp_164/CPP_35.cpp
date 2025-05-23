```c
#include <vector>

float max_element(const std::vector<float>& v) {
  float* end = v.data() + v.size();
  float* begin = v.data();
  if (begin == end) {
    return -10000.0f;
  }
  float max_val = -10000.0f;
  for (float* it = begin; it != end; ++it) {
    if (*it > max_val) {
      max_val = *it;
    }
  }
  return max_val;
}
```
```c
#include <vector>

bool below_threshold(const std::vector<int>& v, int threshold) {
  if (v.empty()) {
    return false;
  }
  size_t size = v.size();
  if (size == 0) {
    return false;
  }
  for (size_t i = 0; i < size; ++i) {
    if (v[i] < threshold) {
      return true;
    }
  }
  return false;
}
```
<|im_end|>
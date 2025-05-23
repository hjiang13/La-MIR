```c
#include <vector>

bool will_it_fly(const std::vector<int>& v, int target) {
  if (v.empty()) {
    return false;
  }
  auto end = v.data() + v.size();
  auto size = end - v.data();
  if (size == 0) {
    return false;
  }
  
  for (size_t i = 0; i < ((size > 1) ? size : 1); ++i) {
    int val = v[i];
    int otherVal = v[size - i - 1];
    if (val == otherVal) {
      continue;
    }
    return false;
  }
  return true;
}
```
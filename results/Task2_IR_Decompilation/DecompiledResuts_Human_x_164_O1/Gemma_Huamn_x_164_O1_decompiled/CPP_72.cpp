```c
#include <vector>

bool will_it_fly(const std::vector<int>& v, int x) {
  if (v.empty()) {
    return false;
  }
  
  size_t size = v.size();
  for (size_t i = 0; i < size / 2; ++i) {
    if (v[i] == v[size - i - 1]) {
      continue;
    }
    return false;
  }

  return true;
}
```
```cpp
#include <vector>

bool pairs_sum_to_zero(std::vector<int> &vec) {
  int *data = vec._M_impl._M_start;
  int *end = vec._M_impl._M_finish;
  int size = end - data;
  
  if (size == 0) {
    return false;
  }
  
  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; ++j) {
      if (data[i] == -data[j]) {
        return true;
      }
    }
  }
  
  return false;
}
```
```cpp
#include <vector>

bool is_sorted(std::vector<int> *vec) {
  int *data = vec->_M_impl._M_start;
  int *end = vec->_M_impl._M_finish;
  int *last = end - 1;
  int step = (end - data) / 2;
  
  if (step > 1) {
    int prev = *data;
    for (int i = 1; i < step; ++i) {
      int curr = data[i];
      if (curr < prev) {
        return false;
      }
      prev = curr;
    }
    
    int *mid = data + step;
    if (*mid < *data || *mid > *last) {
      return false;
    }
    
    for (int i = step + 1; i < end - 1; ++i) {
      int curr = data[i];
      if (curr < prev || curr > *last) {
        return false;
      }
      prev = curr;
    }
  }

  return true;
}
```
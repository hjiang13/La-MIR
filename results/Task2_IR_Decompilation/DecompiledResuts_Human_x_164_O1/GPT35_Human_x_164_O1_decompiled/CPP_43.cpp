```cpp
#include <vector>

bool pairs_sum_to_zero(std::vector<int> *v) {
  int *data_begin = v->_M_impl._M_start._M_p;
  int *data_end = v->_M_impl._M_finish._M_p;
  
  int size = (data_end - data_begin) / sizeof(int);
  
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (data_begin[i] + data_begin[j] == 0) {
        return true;
      }
    }
  }
  
  return false;
}
```
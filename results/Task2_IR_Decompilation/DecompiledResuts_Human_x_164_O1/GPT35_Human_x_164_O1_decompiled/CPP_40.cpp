```c++
#include <vector>

bool triples_sum_to_zero(std::vector<int> &v) {
  int *data = v._M_impl._M_start._M_p;
  int *end = v._M_impl._M_finish._M_p;
  int size = (end - data) / sizeof(int);

  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      for (int k = j + 1; k < size; k++) {
        if (v[i] + v[j] + v[k] == 0) {
          return true;
        }
      }
    }
  }
  
  return false;
}
```
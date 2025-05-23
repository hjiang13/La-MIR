```cpp
#include <vector>

bool pairs_sum_to_zero(std::vector<int>* vec) {
  int* begin = &((*vec)[0]);
  int* end = &((*vec)[1]);
  int size = (end - begin) / sizeof(int);

  if (size == 0) {
    return false;
  }

  int max = size > 1 ? size : 1;

  for (int i = 0; i < max; ++i) {
    for (int j = i + 1; j < size; ++j) {
      if (begin[i] + begin[j] == 0) {
        return true;
      }
    }
  }

  return false;
}
```
```cpp
#include <vector>

bool below_zero(std::vector<int>& vec) {
  int* begin = &vec[0];
  int* end = &vec[1];
  int size = (end - begin) / 4;
  
  if (size > 1) {
    size = size > 0 ? size : 1;
    
    int sum = 0;
    for (int i = 0; i < size; i++) {
      sum += vec[i];
      if (sum < 0) {
        return true;
      }
    }
  }
  
  return false;
}
```
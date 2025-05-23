```cpp
#include <vector>

bool below_threshold(std::vector<int> &vec, int threshold) {
  int *begin = &vec[0];
  int *end = &vec[1];
  long difference = (long)end - (long)begin;
  long max_iterations = difference >> 2;
  
  if (difference == 0) {
    return true;
  } else {
    long iterations = std::max(max_iterations, 1L);
    int value = *begin;
    if (value < threshold) {
      for (long i = 1; i < iterations; i++) {
        value = *(begin + i);
        if (value < threshold) {
          continue;
        } else {
          return false;
        }
      }
    }
    
    return true;
  }
}

```
```cpp
#include <vector>

int smallest_change(std::vector<int> &vec) {
  int *data = vec._M_impl._M_start;
  int *end = vec._M_impl._M_finish;
  int diff = (int)((long)data - (long)end) / 4;
  int iterations = diff / 4 - 1;

  if (iterations == 0) {
    return 0;
  } else {
    int count = 0;
    int index1 = 0;
    int index2 = iterations;
    for (int i = 0; i < iterations; i++) {
      int val1 = data[index1];
      int val2 = data[index2];
      if (val1 != val2) {
        count++;
      }
      index1++;
      index2++;
    }
    return count;
  }
}
```
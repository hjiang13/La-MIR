```cpp
#include <vector>

int smallest_change(std::vector<int> &vec) {
  int size = vec.size();
  int smallestChange = 0;

  for (int i = 0; i < size - 1; i++) {
    if (vec[i] != vec[i + 1]) {
      smallestChange++;
    }
  }

  return smallestChange;
}
```
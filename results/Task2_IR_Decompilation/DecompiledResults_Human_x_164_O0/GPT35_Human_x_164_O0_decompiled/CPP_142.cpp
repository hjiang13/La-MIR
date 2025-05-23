Here is the decompiled C++ code from the given LLVM IR code:

```cpp
#include <vector>

int sum_squares(std::vector<int> *vec) {
  int sum = 0;
  int index = 0;

  for (index = 0; index < vec->size(); index++) {
    if (index % 3 == 0) {
      sum += vec->at(index) * vec->at(index);
    } else if (index % 4 == 0) {
      sum += vec->at(index) * vec->at(index) * vec->at(index);
    } else {
      sum += vec->at(index);
    }
  }

  return sum;
}
```
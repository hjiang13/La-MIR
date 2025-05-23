The provided IR code is a function that takes a vector of integers as input and returns a boolean value. The function checks if the vector contains only positive integers and if the sum of the elements in the vector is below a certain threshold.

Here is the decompiled C++ source code for the provided IR code:
```
#include <vector>

bool below_zero(std::vector<int> &vec) {
  int sum = 0;
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i] < 0) {
      return false;
    }
    sum += vec[i];
  }
  return sum < 0;
}
```
Note that the decompiled code is not exactly the same as the original C++ source code, but it should produce the same output for the same input.
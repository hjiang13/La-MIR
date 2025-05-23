The provided IR code is a function named `_Z11sum_squaresSt6vectorIiSaIiEE` that takes a vector of integers as input and returns an integer. The function iterates over the elements of the vector, squares each element, and returns the sum of the squares.

Here is the decompiled C++ source code for the function:
```
#include <vector>

int sum_squares(std::vector<int> &v) {
  int sum = 0;
  for (int i = 0; i < v.size(); i++) {
    sum += v[i] * v[i];
  }
  return sum;
}
```
Note that the decompiled code is not exactly the same as the original source code, but it should produce the same output for the same input.
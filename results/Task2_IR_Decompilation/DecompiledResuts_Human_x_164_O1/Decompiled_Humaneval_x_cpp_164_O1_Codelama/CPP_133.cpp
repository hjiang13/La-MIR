The provided IR code is for a function that takes a vector of floats as input and returns the sum of the squares of the elements in the vector. The function is implemented using a loop that iterates over the elements of the vector and adds the square of each element to a running total.

Here is the decompiled C++ source code for the function:
```
#include <vector>

int sum_squares(std::vector<float> &v) {
  int total = 0;
  for (int i = 0; i < v.size(); i++) {
    total += v[i] * v[i];
  }
  return total;
}
```
Note that the decompiled code is not exactly the same as the original source code, as the decompiler has made some assumptions about the original code based on the IR. However, the decompiled code should be functionally equivalent to the original code.
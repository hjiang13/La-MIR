The provided IR code is a function that takes two vectors as input and returns a vector that represents the sum of the products of the corresponding elements of the input vectors. The function is implemented using a loop that iterates over the elements of the input vectors and computes the sum of the products element-wise.

Here is the decompiled C++ code for the provided IR code:
```
#include <vector>

std::vector<int> sum_product(std::vector<int> v1, std::vector<int> v2) {
  std::vector<int> result;
  for (int i = 0; i < v1.size(); i++) {
    result.push_back(v1[i] * v2[i]);
  }
  return result;
}
```
Note that the decompiled code assumes that the input vectors have the same size, and it does not perform any bounds checking. Also, the decompiled code uses the `push_back` method to add elements to the result vector, which may not be the most efficient way to do this.
The provided IR code is for a function that takes a vector of integers and an integer as input, and returns an integer. The function appears to be a vectorized implementation of a loop that adds a constant value to each element of the vector, with some additional logic to handle edge cases.

Here is the decompiled C++ code for the function:
```
int add_elements(vector<int> &v, int n) {
  int result = 0;
  for (int i = 0; i < n; i++) {
    result += v[i] + 99;
  }
  return result;
}
```
Note that the decompiled code is not identical to the original source code, as the IR code has been optimized and transformed by the compiler. However, the decompiled code should be functionally equivalent to the original code.
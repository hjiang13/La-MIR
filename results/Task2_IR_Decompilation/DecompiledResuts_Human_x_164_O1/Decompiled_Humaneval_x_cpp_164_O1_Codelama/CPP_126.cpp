The provided IR code is for a function that takes a vector of integers as input and returns a boolean value indicating whether the vector is sorted in ascending order.

Here is the decompiled C++ source code for the function:
```
#include <vector>

bool is_sorted(std::vector<int> &v) {
  if (v.size() <= 1) {
    return true;
  }

  for (int i = 1; i < v.size(); i++) {
    if (v[i] < v[i - 1]) {
      return false;
    }
  }

  return true;
}
```
The decompiled code is in C++ and uses the standard library vector class. The function takes a reference to a vector of integers as input and returns a boolean value indicating whether the vector is sorted in ascending order. The function first checks if the vector has only one element or less, in which case it returns true. Otherwise, it iterates through the vector and checks if each element is less than the previous element. If it finds an element that is less than the previous element, it returns false. If it reaches the end of the vector without finding any elements that are less than the previous element, it returns true.

Note that the decompiled code is not the original source code, but it is functionally equivalent to the original code. The decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process.
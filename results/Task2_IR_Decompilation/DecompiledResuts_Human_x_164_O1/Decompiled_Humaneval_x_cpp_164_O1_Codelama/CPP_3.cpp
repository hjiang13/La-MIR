The provided IR code is for a function that takes a vector of integers as input and returns a boolean value indicating whether the input vector contains only non-negative integers.

Here is the decompiled C++ source code for the function:
```
bool below_zero(vector<int> v) {
  int size = v.size();
  int i = 0;
  while (i < size) {
    if (v[i] < 0) {
      return false;
    }
    i++;
  }
  return true;
}
```
The decompiled code is in C++11, and it uses the `vector` class from the C++ Standard Template Library (STL). The function takes a `vector<int>` as input and returns a `bool` indicating whether the input vector contains only non-negative integers. The function iterates over the elements of the input vector using a `while` loop, and it returns `false` as soon as it encounters a negative integer. If the loop completes without finding any negative integers, the function returns `true`.
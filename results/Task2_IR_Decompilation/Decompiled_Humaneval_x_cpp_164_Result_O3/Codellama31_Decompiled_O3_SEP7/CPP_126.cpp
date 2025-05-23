The provided IR code is a function that takes a vector of integers as input and returns a boolean value indicating whether the vector is sorted in ascending order. The function is implemented using a loop that iterates over the elements of the vector and checks if each element is greater than or equal to the previous element. If the function detects a violation of the sorting order, it returns false. If the loop completes without finding any violations, the function returns true.

Here is the decompiled C++ source code for the function:
```
#include <vector>

bool is_sorted(std::vector<int> v) {
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < v[i - 1]) {
            return false;
        }
    }
    return true;
}
```
Note that the decompiled code is not exactly the same as the original source code, but it should be functionally equivalent. The differences are due to the way the IR code was optimized and the limitations of the decompiler.
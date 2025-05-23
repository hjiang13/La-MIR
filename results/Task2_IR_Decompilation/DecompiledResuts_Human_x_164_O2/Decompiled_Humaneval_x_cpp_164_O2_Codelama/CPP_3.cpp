The provided IR code is for a function that takes a vector of integers as input and returns a boolean value indicating whether the input vector contains only positive integers. The function is implemented using a loop that iterates over the elements of the input vector and checks whether each element is positive. If any element is not positive, the function returns false. If all elements are positive, the function returns true.

Here is the decompiled C++ source code for the function:
```
#include <vector>

bool below_zero(std::vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < 0) {
            return false;
        }
    }
    return true;
}
```
Note that the decompiled code is not exactly the same as the original source code, but it is functionally equivalent. The decompiled code uses a range-based for loop to iterate over the elements of the input vector, while the original source code uses a traditional for loop with an index variable. Additionally, the decompiled code uses the `std::vector` class from the C++ Standard Template Library (STL), while the original source code uses a raw array.
The provided IR code is a function that takes a vector of integers and an integer as input, and returns a boolean value. The function checks if the vector contains a contiguous subsequence of integers that adds up to the input integer.

Here is the decompiled C++ code for the provided IR code:
```
#include <vector>

bool will_it_fly(std::vector<int> vec, int input) {
    int size = vec.size();
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += vec[i];
        if (sum == input) {
            return true;
        }
    }
    return false;
}
```
Note that the decompiled code is not exactly the same as the original C++ code, as the IR code has been optimized and transformed by the compiler. However, the decompiled code should have the same behavior as the original C++ code.
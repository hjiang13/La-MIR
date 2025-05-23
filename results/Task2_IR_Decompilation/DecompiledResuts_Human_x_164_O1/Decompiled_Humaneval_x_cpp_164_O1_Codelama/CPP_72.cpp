The provided IR code is a function that takes a vector of integers and an integer as input, and returns a boolean value. The function checks if the vector contains a contiguous subsequence of integers that add up to the input integer.

Here is the decompiled C++ code:
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
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed during compilation. However, the decompiled code should have the same behavior and functionality as the original source code.
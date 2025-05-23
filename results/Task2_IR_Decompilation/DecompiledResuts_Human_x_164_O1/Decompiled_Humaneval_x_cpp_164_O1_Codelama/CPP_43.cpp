The provided IR code is a function that takes a vector of integers as input and returns a boolean value indicating whether the sum of any two elements in the vector is equal to zero. The function is implemented using a brute force approach, where all possible pairs of elements are compared to find a match.

Here is the decompiled C++ source code for the provided IR code:
```
#include <iostream>
#include <vector>

using namespace std;

bool pairs_sum_to_zero(vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == 0) {
                return true;
            }
        }
    }
    return false;
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed during the compilation process. However, the decompiled code should be functionally equivalent to the original code.
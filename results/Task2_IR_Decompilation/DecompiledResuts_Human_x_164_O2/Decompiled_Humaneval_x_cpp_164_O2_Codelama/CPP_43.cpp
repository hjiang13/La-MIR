The provided IR code is for a function that takes a vector of integers as input and returns a boolean value indicating whether the sum of any two elements in the vector is equal to zero. The function is implemented using a brute force approach, where all possible pairs of elements are checked for the sum being zero.

Here is the decompiled C++ code for the function:
```
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
Note that the decompiled code is not optimized and may not be the most efficient implementation of the function. The original code may have been optimized for performance or readability, and the decompiled code may not reflect those optimizations.
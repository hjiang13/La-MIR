The provided IR code is for a function that takes a vector of integers as input and returns a boolean value indicating whether the sum of the elements in the vector is zero. The function uses a loop to iterate over the elements of the vector and computes the sum. If the sum is zero, the function returns true, otherwise it returns false.

Here is the decompiled C++ code for the function:
```
#include <vector>

bool triples_sum_to_zero(std::vector<int> nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    return sum == 0;
}
```
Note that the decompiled code is not exactly the same as the original code, but it should produce the same output for the same input. The differences are due to the fact that the IR code is a low-level representation of the code and does not include some of the high-level constructs such as loops and conditional statements.
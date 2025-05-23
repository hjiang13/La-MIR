The provided IR code is a function that takes a vector of integers as input and returns a boolean value indicating whether the sum of the elements in the vector is zero. The function is implemented using a loop that iterates over the elements of the vector and adds them to a running sum. If the running sum is ever equal to zero, the function returns true. If the loop completes without the running sum ever being zero, the function returns false.

Here is the decompiled C++ code for the function:
```
#include <vector>

bool triples_sum_to_zero(std::vector<int> nums) {
  int sum = 0;
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
    if (sum == 0) {
      return true;
    }
  }
  return false;
}
```
Note that the decompiled code is not exactly the same as the original C++ code, but it is functionally equivalent. The decompiled code uses a loop to iterate over the elements of the vector, while the original code uses a recursive function to perform the same operation. Additionally, the decompiled code uses a variable to store the running sum, while the original code uses a function parameter to store the sum.
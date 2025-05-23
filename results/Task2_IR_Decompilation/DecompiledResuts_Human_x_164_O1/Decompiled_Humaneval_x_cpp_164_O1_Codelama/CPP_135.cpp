Sure, here's the decompiled C++ source code for the provided IR code:
```
#include <iostream>
#include <vector>

using namespace std;

int can_arrange(vector<int> &nums) {
  int n = nums.size();
  if (n == 0) {
    return -1;
  }

  int max_val = nums[0];
  for (int i = 1; i < n; i++) {
    if (nums[i] > max_val) {
      max_val = nums[i];
    }
  }

  int min_val = nums[0];
  for (int i = 1; i < n; i++) {
    if (nums[i] < min_val) {
      min_val = nums[i];
    }
  }

  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += nums[i];
  }

  if (sum == 0) {
    return -1;
  }

  int avg = sum / n;
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i] > avg) {
      count++;
    }
  }

  if (count == 0) {
    return -1;
  }

  int result = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i] > avg) {
      result += nums[i] - avg;
    }
  }

  return result;
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original source code.
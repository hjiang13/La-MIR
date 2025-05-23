```c
#include <vector>

int count_nums(const std::vector<int>& nums) {
  int count = 0;
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] > 0) {
      int sum = 0;
      int num = nums[i];
      while (num > 0) {
        sum += num % 10;
        num /= 10;
      }
      if (sum > nums[i]) {
        count++;
      }
    }
  }
  return count;
}
```
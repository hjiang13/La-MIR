```c
#include <vector>
int count_nums(std::vector<int>& nums) {
  int count = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] > 0) {
      int sum = 0;
      int n = std::abs(nums[i]);
      while (n > 9) {
        sum += n % 10;
        n /= 10;
      }
      sum += n;
      if (sum > nums[i]) {
        count++;
      }
    }
  }
  return count;
}
```
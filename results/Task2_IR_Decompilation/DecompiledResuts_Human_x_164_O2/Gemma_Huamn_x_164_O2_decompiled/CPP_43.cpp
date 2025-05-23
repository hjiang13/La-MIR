```c
#include <vector>

bool pairs_sum_to_zero(const std::vector<int>& nums) {
  const int* end = nums.data() + nums.size();
  const int* it = nums.data() + 1;
  
  if (end == it) {
    return false;
  }

  for (size_t i = 1; i < nums.size(); ++i) {
    for (size_t j = i + 1; j < nums.size(); ++j) {
      if (nums[i - 1] == -nums[j - 1]) {
        return true;
      }
    }
  }

  return false;
}
```
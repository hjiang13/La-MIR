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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (count_nums({}) == 0);
    assert (count_nums({-1, -2, 0}) == 0);
    assert (count_nums({1, 1, 2, -2, 3, 4, 5}) == 6);
    assert (count_nums({1, 6, 9, -6, 0, 1, 5}) == 5);
    assert (count_nums({1, 100, 98, -7, 1, -1}) == 4);
    assert (count_nums({12, 23, 34, -45, -56, 0}) == 5);
    assert (count_nums({-0, 1}) == 1);
    assert (count_nums({1}) == 1);
}

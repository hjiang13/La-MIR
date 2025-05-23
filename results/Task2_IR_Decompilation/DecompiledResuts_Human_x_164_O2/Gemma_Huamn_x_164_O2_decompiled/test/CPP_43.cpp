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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (pairs_sum_to_zero({1, 3, 5, 0}) == false);
    assert (pairs_sum_to_zero({1, 3, -2, 1}) == false);
    assert (pairs_sum_to_zero({1, 2, 3, 7}) == false);
    assert (pairs_sum_to_zero({2, 4, -5, 3, 5, 7}) == true);
    assert (pairs_sum_to_zero({1}) == false);
    assert (pairs_sum_to_zero({-3, 9, -1, 3, 2, 30}) == true);
    assert (pairs_sum_to_zero({-3, 9, -1, 3, 2, 31}) == true);
    assert (pairs_sum_to_zero({-3, 9, -1, 4, 2, 30}) == false);
    assert (pairs_sum_to_zero({-3, 9, -1, 4, 2, 31}) == false);
}

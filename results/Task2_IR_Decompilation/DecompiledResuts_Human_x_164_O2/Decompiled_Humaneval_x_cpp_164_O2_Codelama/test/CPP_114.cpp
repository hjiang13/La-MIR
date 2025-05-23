#include <vector>

int minSubArraySum(std::vector<int> &nums) {
  if (nums.size() == 1) {
    return nums[0];
  }

  int mid = nums.size() / 2;
  int leftSum = minSubArraySum(std::vector<int>(nums.begin(), nums.begin() + mid));
  int rightSum = minSubArraySum(std::vector<int>(nums.begin() + mid, nums.end()));

  int minLeft = leftSum;
  int minRight = rightSum;
  for (int i = mid; i < nums.size(); i++) {
    minLeft = std::min(minLeft, leftSum + nums[i]);
    minRight = std::min(minRight, rightSum + nums[i]);
  }

  return std::min(minLeft, minRight);
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (minSubArraySum({2, 3, 4, 1, 2, 4}) == 1);
    assert (minSubArraySum({-1, -2, -3}) == -6);
    assert (minSubArraySum({-1, -2, -3, 2, -10}) == -14);
    assert (minSubArraySum({-9999999999999999}) == -9999999999999999);
    assert (minSubArraySum({0, 10, 20, 1000000}) == 0);
    assert (minSubArraySum({-1, -2, -3, 10, -5}) == -6);
    assert (minSubArraySum({100, -1, -2, -3, 10, -5}) == -6);
    assert (minSubArraySum({10, 11, 13, 8, 3, 4}) == 3);
    assert (minSubArraySum({100, -33, 32, -1, 0, -2}) == -33);
    assert (minSubArraySum({-10}) == -10);
    assert (minSubArraySum({7}) == 7);
    assert (minSubArraySum({1, -1}) == -1);
}

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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (can_arrange({1,2,4,3,5})==3);
    assert (can_arrange({1,2,4,5})==-1);
    assert (can_arrange({1,4,2,5,6,7,8,9,10})==2);
    assert (can_arrange({4,8,5,7,3})==4);
    assert (can_arrange({})==-1);
}

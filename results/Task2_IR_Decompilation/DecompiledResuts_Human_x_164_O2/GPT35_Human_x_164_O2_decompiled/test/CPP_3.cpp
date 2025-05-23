```cpp
#include <vector>

bool below_zero(std::vector<int> &vec) {
  int *begin = &vec[0];
  int *end = &vec[0] + vec.size();
  int diff = (end - begin) >> 2;
  if (diff == 0) {
    return false;
  }

  int max_diff = __umax_i64(diff, 1);
  int sum = *begin;
  if (sum < 0) {
    return false;
  }

  for (int i = 1; i < max_diff; i++) {
    int curr = *(begin + i);
    sum += curr;
    if (sum < 0) {
      return false;
    }
  }

  return true;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (below_zero({}) == false);
    assert (below_zero({1, 2, -3, 1, 2, -3}) == false);
    assert (below_zero({1, 2, -4, 5, 6}) == true);
    assert (below_zero({1, -1, 2, -2, 5, -5, 4, -4}) == false);
    assert (below_zero({1, -1, 2, -2, 5, -5, 4, -5}) == true);
    assert (below_zero({1, -2, 2, -2, 5, -5, 4, -4}) == true);
}
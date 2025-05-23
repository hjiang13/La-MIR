#include <vector>

bool below_zero(std::vector<int> &vec) {
  int sum = 0;
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i] < 0) {
      return false;
    }
    sum += vec[i];
  }
  return sum < 0;
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
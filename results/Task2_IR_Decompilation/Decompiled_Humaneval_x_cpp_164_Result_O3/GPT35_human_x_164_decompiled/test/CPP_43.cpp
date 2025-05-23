#include <vector>

bool pairs_sum_to_zero(std::vector<int> &vec) {
  int *data = vec._M_impl._M_start;
  int *end = vec._M_impl._M_finish;
  int size = end - data;
  
  if (size == 0) {
    return false;
  }
  
  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; ++j) {
      if (data[i] == -data[j]) {
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

#include <stdint.h>

int32_t* pairs_sum_to_zero(int32_t* vec, int32_t len) {
  int32_t* end = vec + len;
  int32_t* i = vec + 1;
  int32_t* j = vec;
  for (; i < end; ++i) {
    for (j = vec; j < i; ++j) {
      if (*i + *j == 0) {
        return 1;
      }
    }
  }
  return 0;
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

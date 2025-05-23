#include <stdint.h>

int below_zero(int* vector, int size) {
  if (size == 0) {
    return 0;
  }
  int64_t sum = 0;
  for (int i = 0; i < size; i++) {
    sum += vector[i];
    if (sum < 0) {
      return 1;
    }
  }
  return 0;
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
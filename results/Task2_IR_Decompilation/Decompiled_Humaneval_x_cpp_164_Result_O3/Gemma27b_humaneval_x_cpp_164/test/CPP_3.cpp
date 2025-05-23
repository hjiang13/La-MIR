#include <stdint.h>

int below_zero(int* arr, int size) {
  if (size == 0) {
    return 0;
  }
  if (arr[0] < 0) {
    return 1;
  }
  for (int i = 1; i < size; i++) {
    if (arr[i] + arr[i - 1] < 0) {
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
#include <stdint.h>

int solutions(int32_t* arr, size_t size) {
  if (size == 0) {
    return 0;
  }

  size_t n = size / 2;
  if (n < 2) {
    n = 2;
  }

  int32_t sum = 0;
  for (size_t i = 0; i < n; i += 4) {
    int32_t a = arr[2*i];
    int32_t b = arr[2*i + 1];
    int32_t c = arr[2*i + 2];
    int32_t d = arr[2*i + 3];

    sum += (a % 2 == 1) ? a : 0;
    sum += (b % 2 == 1) ? b : 0;
    sum += (c % 2 == 1) ? c : 0;
    sum += (d % 2 == 1) ? d : 0;
  }

  for (size_t i = 2*n; i < size; ++i) {
    sum += (arr[i] % 2 == 1) ? arr[i] : 0;
  }

  return sum;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (solutions({5, 8, 7, 1})    == 12);
    assert (solutions({3, 3, 3, 3, 3}) == 9);
    assert (solutions({30, 13, 24, 321}) == 0);
    assert (solutions({5, 9}) == 5);
    assert (solutions({2, 4, 8}) == 0);
    assert (solutions({30, 13, 23, 32}) == 23);
    assert (solutions({3, 13, 2, 9}) == 3);
}

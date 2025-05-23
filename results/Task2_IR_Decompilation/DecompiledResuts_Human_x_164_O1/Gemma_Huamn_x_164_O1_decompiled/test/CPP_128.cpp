#include <stdint.h>

int prod_signs(int* a, int size) {
  if (size == 0) {
    return -32768;
  }
  int64_t n = size >> 2;
  if (size < 2) {
    n = 1;
  }
  int sum = 0;
  int prod = 1;
  for (int64_t i = 0; i < n; ++i) {
    int val = a[i];
    sum += abs(val);
    prod = (val < 0) ? -prod : prod;
  }
  return prod * sum;
}


#undef NDEBUG
#include<assert.h>
int main(){
    assert (prod_signs({1, 2, 2, -4}) == -9);
    assert (prod_signs({0, 1}) == 0);
    assert (prod_signs({1, 1, 1, 2, 3, -1, 1}) == -10);
    assert (prod_signs({}) == -32768);
    assert (prod_signs({2, 4,1, 2, -1, -1, 9}) == 20);
    assert (prod_signs({-1, 1, -1, 1}) == 4);
    assert (prod_signs({-1, 1, 1, 1}) == -4);
    assert (prod_signs({-1, 1, 1, 0}) == 0);
}

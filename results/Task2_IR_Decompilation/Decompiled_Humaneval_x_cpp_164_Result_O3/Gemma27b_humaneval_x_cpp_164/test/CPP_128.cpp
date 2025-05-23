#include <stdint.h>

int prod_signs(int32_t* arr, size_t size) {
  if (size == 0) {
    return -32768;
  }

  int32_t sum = 1;
  int32_t prod = 0;
  for (size_t i = 0; i < size - (size % 2); i += 2) {
    int32_t a = arr[i];
    int32_t b = arr[i + 1];
    prod += abs(a) + abs(b);
    sum = (a == 0 ? 0 : (a > 0 ? sum : -sum)) * (b == 0 ? 0 : (b > 0 ? 1 : -1));
  }

  if (size % 2 != 0) {
    prod += abs(arr[size - 1]);
    sum = (arr[size - 1] == 0 ? 0 : (arr[size - 1] > 0 ? sum : -sum));
  }

  return sum * prod;
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

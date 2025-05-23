#include <stdint.h>

int32_t _Z9monotonicSt6vectorIfSaIfEE(const float * vec, size_t size) {
  if (size <= 1) {
    return 0;
  }

  float first = vec[0];

  for (size_t i = 1; i < size; ++i) {
    if (vec[i] > first) {
      return 1;
    }
    if (vec[i] < first) {
      return 1;
    }
    first = vec[i];
  }

  return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (monotonic({1, 2, 4, 10}) == true);
    assert (monotonic({1, 2, 4, 20}) == true);
    assert (monotonic({1, 20, 4, 10}) == false);
    assert (monotonic({4, 1, 0, -10}) == true);
    assert (monotonic({4, 1, 1, 0}) == true);
    assert (monotonic({1, 2, 3, 2, 5, 60}) == false);
    assert (monotonic({1, 2, 3, 4, 5, 60}) == true);
    assert (monotonic({9, 9, 9, 9}) == true);
}

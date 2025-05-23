#include <stddef.h>

int monotonic(float* data, size_t size) {
  if (size <= 1) {
    return 0;
  }
  
  float first = data[0];
  for (size_t i = 1; i < size; ++i) {
    if ((data[i] > first) && (data[i] < data[i - 1])) {
      return 0;
    }
    first = data[i];
  }
  return 1;
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

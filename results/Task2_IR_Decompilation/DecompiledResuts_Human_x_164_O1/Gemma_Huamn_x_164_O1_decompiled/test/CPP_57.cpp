#include <stdbool.h>

bool monotonic(float* arr, size_t size) {
  if (size <= 1) {
    return true;
  }

  int increasing = 0;
  int decreasing = 0;

  for (size_t i = 1; i < size; i++) {
    if (arr[i] > arr[i - 1]) {
      increasing = 1;
    }
    if (arr[i] < arr[i - 1]) {
      decreasing = 1;
    }
  }
  return increasing + decreasing != 2;
}
```
<|im_end|>
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

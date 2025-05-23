#include <math.h>
#include <stdint.h>

int has_close_elements(float* arr, size_t size, float threshold) {
  if (size == 0) {
    return 0;
  }

  for (size_t i = 1; i < size; ++i) {
    for (size_t j = 0; j < i; ++j) {
      float diff = fabs(arr[i] - arr[j]);
      if (diff < threshold) {
        return 1;
      }
    }
  }
  return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    vector<float> a={1.0, 2.0, 3.9, 4.0, 5.0, 2.2};
    assert (has_close_elements(a, 0.3)==true);
    assert (has_close_elements(a, 0.05) == false);

    assert (has_close_elements({1.0, 2.0, 5.9, 4.0, 5.0}, 0.95) == true);
    assert (has_close_elements({1.0, 2.0, 5.9, 4.0, 5.0}, 0.8) ==false);
    assert (has_close_elements({1.0, 2.0, 3.0, 4.0, 5.0}, 2.0) == true);
    assert (has_close_elements({1.1, 2.2, 3.1, 4.1, 5.1}, 1.0) == true);
    assert (has_close_elements({1.1, 2.2, 3.1, 4.1, 5.1}, 0.5) == false);
    
}

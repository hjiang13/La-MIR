```cpp
#include <vector>

float max_element(std::vector<float> &v) {
  float *data = v._M_impl._M_start;
  float *end = v._M_impl._M_finish;
  
  if (data == end) {
    return -10000.0;
  }
  
  size_t size = end - data;
  size_t n = (size >> 2) + ((size & 3) ? 1 : 0);
  
  float result = -10000.0;
  for (size_t i = 0; i < n; ++i) {
    float val = data[i];
    result = (result < val) ? val : result;
  }
  
  return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(max_element({1, 2, 3})- 3)<1e-4);
    assert (abs(max_element({5, 3, -5, 2, -3, 3, 9, 0, 124, 1, -10})- 124)<1e-4);
}

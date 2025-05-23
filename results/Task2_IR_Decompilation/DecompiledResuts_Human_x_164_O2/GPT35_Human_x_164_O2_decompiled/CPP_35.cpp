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
```
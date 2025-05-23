```c
#include <vector>
#include <cmath>

int sum_squares(const std::vector<float>& v) {
  float* end = v.data() + v.size();
  float* begin = v.data();
  
  if (end == begin) {
    return 0;
  }
  
  size_t count = (end - begin) / sizeof(float);
  size_t iters = std::max(count / 4, 1ul);

  int sum = 0;
  for (size_t i = 0; i < iters; ++i) {
    float val = v[i];
    sum += static_cast<int>(std::ceil(val) * std::ceil(val));
  }
  return sum;
}

```
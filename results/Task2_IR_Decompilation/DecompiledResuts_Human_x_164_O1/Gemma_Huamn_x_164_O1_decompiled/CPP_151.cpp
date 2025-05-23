```c
#include <vector>

int64_t double_the_difference(const std::vector<float>& vec) {
  float* end = vec.data() + vec.size();
  float* begin = vec.data();
  int64_t size = end - begin;
  if (size == 0) {
    return 0;
  }
  int64_t count = (size / 4) > 1 ? (size / 4) : 1;
  int64_t sum = 0;
  for (int64_t i = 0; i < count; ++i) {
    float val = begin[i];
    float rounded = roundf(val);
    float diff = val - rounded;
    if (diff < 0.0001 && val > 0) {
      int32_t roundedInt = (int32_t)rounded;
      if (roundedInt % 2 == 1) {
        sum += roundedInt * roundedInt;
      }
    }
  }
  return sum;
}
```
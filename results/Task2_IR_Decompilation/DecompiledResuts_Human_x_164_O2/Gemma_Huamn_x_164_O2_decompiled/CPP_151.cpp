```c
#include <vector>

extern "C" long long double_the_difference(std::vector<float> const& v) {
  auto size = v.size();
  if (size == 0) {
    return 0;
  }
  long long count = 0;
  for (long long i = 0; i < size; ++i) {
    float val = v[i];
    float rounded = roundf(val);
    float diff = val - rounded;
    if (diff < 0.0001f && val > 0.0f) {
      int rounded_int = static_cast<int>(rounded);
      if (rounded_int % 2 == 1) {
        count += rounded_int * rounded_int;
      }
    }
  }
  return count;
}
```
```c
#include <vector>
#include <cmath>

int sum_squares(const std::vector<float>& vec) {
  const float* begin = vec.data() + vec.size();
  const float* end = vec.data();
  if (begin == end) {
    return 0;
  }
  size_t size = (begin - end) / 2;
  size_t unroll_size = std::max(size / 2, 1u);
  size_t remainder = size % 2;
  if (size <= 1) {
    int sum = 0;
    for (const float* it = end; it != begin; ++it) {
      sum += static_cast<int>(std::ceil(*it) * std::ceil(*it));
    }
    return sum;
  }
  int sum = 0;
  for (size_t i = 0; i < unroll_size; ++i) {
    const float* it1 = end + 2 * i;
    const float* it2 = it1 + 1;
    sum += static_cast<int>(std::ceil(*it1) * std::ceil(*it1) + std::ceil(*it2) * std::ceil(*it2));
  }
  if (remainder) {
    sum += static_cast<int>(std::ceil(*begin - 2) * std::ceil(*begin - 2));
  }
  return sum;
}
```
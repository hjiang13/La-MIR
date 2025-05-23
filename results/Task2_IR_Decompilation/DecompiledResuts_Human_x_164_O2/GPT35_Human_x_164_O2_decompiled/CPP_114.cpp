```cpp
#include <vector>
#include <iostream>

long long minSubArraySum(std::vector<long> const &vec) {
  long long *ptr = vec.data();

  long long size = vec.size();
  long long sum = 0;
  long long min_sum = 0;

  for (long long i = 0; i < size; ++i) {
    sum += ptr[i];
    min_sum = std::min(sum, min_sum);
  }

  return min_sum;
}
```
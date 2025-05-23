```c++
#include <vector>

long long minSubArraySum(std::vector<long> &vec) {
  long long *data = vec._M_impl._M_start._M_p;
  long long size = vec._M_impl._M_finish._M_p - vec._M_impl._M_start._M_p;
  long long subArraySize = size >> 3;
  
  if (subArraySize > 1) {
    long long odd = subArraySize & 1;
    if (size == 16) {
      if (odd) {
        subArraySize &= -2;
      }
    }
    
    long long sum = 0;
    long long minSum = 0;
    for (long long i = 0; i < subArraySize; ++i) {
      long long current = data[i];
      sum += current < 0 ? current : 0;
      minSum = sum < minSum ? sum : minSum;
    }
    
    return minSum;
  }
  
  return 0;
}
```
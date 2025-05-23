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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (minSubArraySum({2, 3, 4, 1, 2, 4}) == 1);
    assert (minSubArraySum({-1, -2, -3}) == -6);
    assert (minSubArraySum({-1, -2, -3, 2, -10}) == -14);
    assert (minSubArraySum({-9999999999999999}) == -9999999999999999);
    assert (minSubArraySum({0, 10, 20, 1000000}) == 0);
    assert (minSubArraySum({-1, -2, -3, 10, -5}) == -6);
    assert (minSubArraySum({100, -1, -2, -3, 10, -5}) == -6);
    assert (minSubArraySum({10, 11, 13, 8, 3, 4}) == 3);
    assert (minSubArraySum({100, -33, 32, -1, 0, -2}) == -33);
    assert (minSubArraySum({-10}) == -10);
    assert (minSubArraySum({7}) == 7);
    assert (minSubArraySum({1, -1}) == -1);
}

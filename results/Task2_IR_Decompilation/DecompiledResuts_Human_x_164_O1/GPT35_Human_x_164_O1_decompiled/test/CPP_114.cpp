```cpp
#include <vector>

long long minSubArraySum(std::vector<long>& vec) {
  long long* ptr1 = &vec[0];
  long long sum = *ptr1;
  long long* ptr2 = &vec[1];
  long long diff = (long long)ptr2 - (long long)ptr1;
  long long size = diff >> 3;
  
  if (size > 1) {
    long long result = sum;
    long long index = 1;
    
    while (index < size) {
      long long value = *(ptr1 + index);
      long long prev = index < 0 ? index : 0;
      long long temp = value + prev;
      
      if (temp < result) {
        result = temp;
      }
      
      index++;
    }
    
    return result;
  } else {
    return sum;
  }
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

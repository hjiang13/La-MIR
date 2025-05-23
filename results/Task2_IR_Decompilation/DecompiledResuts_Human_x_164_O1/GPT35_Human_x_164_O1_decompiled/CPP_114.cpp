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
```
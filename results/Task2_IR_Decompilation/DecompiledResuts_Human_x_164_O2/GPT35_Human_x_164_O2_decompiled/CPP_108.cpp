```cpp
#include <vector>

int count_nums(std::vector<int> &vec) {
  int *begin = vec._M_impl._M_start._M_p;
  int *end = vec._M_impl._M_finish._M_p;
  long long diff = (long long)begin - (long long)end;
  
  if (diff == 0) {
    return 0;
  } else {
    int count = 0;
    long long max_count = llvm.umax.i64(diff >> 2, 1);
    
    for (long long i = 0; i < max_count; ++i) {
      int value = *(end + i);
      
      if (value > 0) {
        int temp = value < -9 ? -value : value;
        int sum = 0;
        
        while (temp > 0) {
          sum += temp % 10;
          temp /= 10;
          
          if (temp > 99) {
            continue;
          } else {
            break;
          }
        }
        
        count += (sum > 0) ? 1 : 0;
      } else {
        continue;
      }
    }
    
    return count;
  }
}
```
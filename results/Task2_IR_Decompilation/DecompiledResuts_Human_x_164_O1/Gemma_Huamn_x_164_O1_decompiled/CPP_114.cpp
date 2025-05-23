```c
#include <stdint.h>
long long minSubArraySum(long long* arr, long long n) {
  long long min_sum = arr[0];
  for (long long i = 1; i < n; i++) {
    long long curr_sum = arr[i];
    if (curr_sum < min_sum) {
      min_sum = curr_sum;
    }
    for (long long j = i - 1; j >= 0; j--) {
      curr_sum += arr[j];
      if (curr_sum < min_sum) {
        min_sum = curr_sum;
      }
    }
  }
  return min_sum;
}
```
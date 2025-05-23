```c
#include <stddef.h>

long long minSubArraySum(long long* arr, size_t n) {
  if (n <= 1) {
    return arr[0];
  }

  long long minSum = arr[0];
  long long currentSum = arr[0];
  for (size_t i = 1; i < n; i++) {
    currentSum = (currentSum < 0) ? 0 : currentSum;
    currentSum += arr[i];
    if (currentSum < minSum) {
      minSum = currentSum;
    }
  }
  return minSum;
}
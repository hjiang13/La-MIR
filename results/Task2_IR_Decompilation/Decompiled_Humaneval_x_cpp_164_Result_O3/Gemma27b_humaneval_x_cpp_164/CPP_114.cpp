```c
long long minSubArraySum(long long* arr, long long len) {
  long long minSum = arr[0];
  for (long long i = 1; i < len; i++) {
    long long currentSum = arr[i];
    if (currentSum < minSum) {
      minSum = currentSum;
    }
    for (long long j = i - 1; j >= 0; j--) {
      currentSum += arr[j];
      if (currentSum < minSum) {
        minSum = currentSum;
      }
    }
  }
  return minSum;
}
```
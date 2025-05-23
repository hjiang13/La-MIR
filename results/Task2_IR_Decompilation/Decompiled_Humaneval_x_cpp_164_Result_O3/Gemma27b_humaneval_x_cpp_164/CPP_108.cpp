```c
int count_nums(int* arr, int size) {
  if (size == 0) {
    return 0;
  }
  long long int nElements = size / 4;
  long long int nIterations = (nElements > 1) ? nElements : 1;
  int count = 0;
  for (long long int i = 0; i < nIterations; i++) {
    int num = arr[i];
    if (num > 0) {
      int sum = 0;
      while (num > 0) {
        sum += num % 10;
        num /= 10;
      }
      if (sum > num) {
        count += 1;
      }
    }
  }
  return count;
}
```
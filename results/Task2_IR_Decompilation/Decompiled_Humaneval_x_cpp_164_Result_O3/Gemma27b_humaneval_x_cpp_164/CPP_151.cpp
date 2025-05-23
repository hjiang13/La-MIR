```c
#include <stdlib.h>

long long int double_the_difference(float *arr, long long int size) {
  long long int diff = (char *) (arr + size) - (char *) arr;
  if (diff == 0) {
    return 0;
  }
  long long int num_elements = diff / sizeof(float);
  if (num_elements < 1) {
    num_elements = 1;
  }
  long long int sum = 0;
  for (long long int i = 0; i < num_elements; i++) {
    float val = arr[i];
    float rounded_val = roundf(val);
    float diff = val - rounded_val;
    if (diff < 0.0001 && val > 0.0) {
      int rounded_int = (int) rounded_val;
      if (rounded_int % 2 == 1) {
        sum += rounded_int * rounded_int;
      }
    }
  }
  return sum;
}
```
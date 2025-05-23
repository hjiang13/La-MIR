```c
#include <stdlib.h>

void sum_product(int *result, int *a, int size) {
  int sum = 0;
  int product = 1;
  for (int i = 0; i < size; i++) {
    sum += a[i];
    product *= a[i];
  }
  result[0] = sum;
  result[1] = product;
}
```
```c
#include <stdio.h>

int add(int *begin, int *end) {
  int sum = 0;
  while (begin != end) {
    sum += *begin;
    ++begin;
  }
  return sum;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int sum = add(arr, arr + 5);
  printf("Sum: %d\n", sum);
  return 0;
}

```
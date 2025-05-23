```c
#include <stdint.h>

int32_t pairs_sum_to_zero(int32_t* arr, int32_t size) {
 int32_t i = 0;
 int32_t j = 1;
 while (i < size) {
  while (j < size) {
   if (arr[i] + arr[j] == 0) {
    return 1;
   }
   j++;
  }
  i++;
  j = i + 1;
 }
 return 0;
}

```
```c
#include <stdint.h>

int32_t _Z8max_fillSt6vectorIS_IiSaIiEESaIS1_EEi(
    void* arg0, int32_t arg1) {
  int32_t* ptr = *(int32_t**)((char*)arg0 + 16);
  int32_t* ptr2 = *(int32_t**)((char*)arg0 + 8);
  int64_t len = (char*)ptr - (char*)ptr2;
  if (len == 0) {
    return 0;
  }
  int64_t size = len / 24;
  int64_t num_loops = (size < 1) ? 1 : size;
  int32_t sum = 0;
  for (int64_t i = 0; i < num_loops; i++) {
    int32_t* ptr3 = ptr2 + i * 24;
    int32_t* ptr4 = ptr3 + 24;
    int32_t sum1 = 0;
    int32_t sum2 = 0;
    for (int32_t j = 0; j < 6; j++) {
      sum1 += ptr3[j];
      sum2 += ptr4[j];
    }
    sum += sum1 + sum2;
  }
  if (len % 24 != 0) {
    int32_t i = num_loops * 24;
    for (; i < len / 4; i += 4) {
      sum += ptr2[i] + ptr2[i + 1] + ptr2[i + 2] + ptr2[i + 3];
    }
    for (; i < len; i++) {
      sum += ptr2[i];
    }
  }
  return sum;
}
```
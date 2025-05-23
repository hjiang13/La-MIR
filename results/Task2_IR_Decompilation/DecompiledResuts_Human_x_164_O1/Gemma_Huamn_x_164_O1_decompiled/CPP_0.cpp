```c
#include <stdlib.h>

float llvm_fabs_f32(float);
unsigned long long llvm_umax_i64(unsigned long long, unsigned long long);

int has_close_elements(float *v, unsigned long long n, float epsilon) {
  if (n == 0) return 0;

  unsigned long long i = 0;
  unsigned long long j = 1;
  while (j < n) {
    float diff = v[i] - v[j];
    if (llvm_fabs_f32(diff) < epsilon) return 1;
    i = j;
    j++;
  }
  return 0;
}
```
```c
#include <stdint.h>

void _Z9incr_listSt6vectorIiSaIiEE(int* out, int* in) {
  int* end = in + (in[1] - in[0]) / 4;
  for (; in < end; in += 4) {
    *(in) += 1;
    *(in + 1) += 1;
    *(in + 2) += 1;
    *(in + 3) += 1;
  }
  if ((in[1] - in[0]) % 4 != 0) {
    for (; in < end + ((in[1] - in[0]) % 4); in++) {
      *in += 1;
    }
  }
  out = in;
  out[1] = end;
  out[2] = end;

  for (int i = 0; i < 24 / sizeof(int); i++) {
    in[i] = 0;
  }
}
```
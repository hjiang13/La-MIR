```c
#include <stdint.h>

void incr_list(int* sret, int* arg) {
  int* end = arg + ((int*)(arg + 1) - arg);
  int* begin = arg;
  while (begin != end) {
    *begin++ += 1;
  }
  int* sret_begin = begin;
  int* sret_end = end;
  sret = begin;
  sret_begin = end;
  sret_end = end;
  for (int i = 0; i < 24; ++i) {
    *(((char*)arg) + i) = 0;
  }
}

int main() {
  return 0;
}

```
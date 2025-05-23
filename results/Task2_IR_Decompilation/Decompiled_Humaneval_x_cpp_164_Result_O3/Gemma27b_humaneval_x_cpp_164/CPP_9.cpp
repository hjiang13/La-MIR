```c
#include <stdlib.h>

void rolling_maxSt6vectorIiSaIiEE(void* __return_buffer, void* arg1) {
  memset(__return_buffer, 0, 24);
  int* end = *(int**)((char*)arg1 + 24);
  int* begin = *(int**)((char*)arg1 + 16);
  int* ret_end = (int*)__return_buffer + 2;
  int* ret_begin = (int*)__return_buffer + 1;
  if (begin == end) {
    return;
  }
  int* i = begin;
  int max_val = *i;
  *ret_begin = i;
  *ret_end = max_val;
  for (i++; i != end; i++) {
    if (*i > max_val) {
      max_val = *i;
      *ret_end = max_val;
      ret_end++;
    }
  }
}
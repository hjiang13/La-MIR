```c
#include <stdlib.h>

typedef struct {
  int* _M_start;
  int* _M_finish;
  int* _M_end_of_storage;
} std_vector_int;

void count_up_to_i(std_vector_int* v, int i) {
  if (i <= 2) {
    return;
  }
  int* v_start = v->_M_start;
  int* v_finish = v->_M_finish;
  int* v_end_of_storage = v->_M_end_of_storage;

  if (v_start == NULL) {
    v_start = (int*)malloc(sizeof(int) * 2);
    v_finish = v_start;
    v_end_of_storage = v_start + 2;
  }

  for (int j = 2; j < i; ++j) {
    if (v_finish == v_end_of_storage) {
      size_t new_size = (v_end_of_storage - v_start) * 2;
      int* new_block = (int*)malloc(sizeof(int) * new_size);
      for (int k = 0; k < (v_finish - v_start); ++k) {
        new_block[k] = v_start[k];
      }
      free(v_start);
      v_start = new_block;
      v_finish = new_block + (v_finish - v_start);
      v_end_of_storage = new_block + new_size;
    }
    *v_finish = j;
    ++v_finish;
  }
  v->_M_start = v_start;
  v->_M_finish = v_finish;
  v->_M_end_of_storage = v_end_of_storage;
}
```
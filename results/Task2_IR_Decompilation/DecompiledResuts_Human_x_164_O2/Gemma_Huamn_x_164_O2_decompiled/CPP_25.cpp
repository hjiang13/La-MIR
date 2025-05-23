```c
#include <stdlib.h>

struct std_vector {
  void** _M_impl;
};

struct std_vector_base {
  struct std_vector_base_impl* _M_impl_data;
};

struct std_vector_base_impl {
  int* _M_start;
  int* _M_finish;
  int* _M_end_of_storage;
};

void factorizei(struct std_vector* result, int n) {
  result->_M_impl = (void**)malloc(sizeof(struct std_vector_base));
  struct std_vector_base* base = (struct std_vector_base*)result->_M_impl;
  base->_M_impl_data = (struct std_vector_base_impl*)malloc(sizeof(struct std_vector_base_impl));
  struct std_vector_base_impl* impl = base->_M_impl_data;
  impl->_M_start = NULL;
  impl->_M_finish = NULL;
  impl->_M_end_of_storage = NULL;
  if (n < 4) {
    return;
  }
  int* p = NULL;
  int* q = NULL;
  int i = 2;
  while (i * i <= n) {
    if (n % i == 0) {
      if (p == NULL) {
        p = (int*)malloc(sizeof(int));
        impl->_M_start = p;
        impl->_M_finish = p;
        impl->_M_end_of_storage = p + 1;
      } else {
        size_t size = impl->_M_finish - impl->_M_start;
        size_t new_size = size * 2;
        int* new_p = (int*)malloc(sizeof(int) * new_size);
        for (int j = 0; j < size; j++) {
          new_p[j] = impl->_M_start[j];
        }
        impl->_M_start = new_p;
        impl->_M_finish = new_p + size;
        impl->_M_end_of_storage = new_p + new_size;
      }
      *impl->_M_finish = i;
      impl->_M_finish++;
      n /= i;
    } else {
      i++;
    }
  }
  if (n > 1) {
    if (p == NULL) {
      p = (int*)malloc(sizeof(int));
      impl->_M_start = p;
      impl->_M_finish = p;
      impl->_M_end_of_storage = p + 1;
    } else {
      size_t size = impl->_M_finish - impl->_M_start;
      size_t new_size = size + 1;
      int* new_p = (int*)malloc(sizeof(int) * new_size);
      for (int j = 0; j < size; j++) {
        new_p[j] = impl->_M_start[j];
      }
      impl->_M_start = new_p;
      impl->_M_finish = new_p + size;
      impl->_M_end_of_storage = new_p + new_size;
    }
    *impl->_M_finish = n;
    impl->_M_finish++;
  }
}

```
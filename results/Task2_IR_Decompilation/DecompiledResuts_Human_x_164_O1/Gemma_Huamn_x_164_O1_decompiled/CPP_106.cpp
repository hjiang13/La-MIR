```c
#include <stdlib.h>

struct std_vector {
  struct std_vector_base *data;
};

struct std_vector_base {
  struct std_vector_base_impl_data *impl;
};

struct std_vector_base_impl_data {
  int *begin;
  int *end;
  int *capacity;
};

void _ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_(
    struct std_vector *this,
    int *position,
    int *value) {
  int *begin = this->data->impl->begin;
  int *end = this->data->impl->end;
  int *capacity = this->data->impl->capacity;
  ptrdiff_t size = end - begin;
  ptrdiff_t new_size = (size == 9223372036854775804) ? 0 : size;
  if (size == 0) {
    new_size = 1;
  } else {
    new_size += size;
  }
  if (new_size > 2305843009213693951) {
    abort();
  }
  int *new_begin = malloc(new_size * sizeof(int));
  if (new_begin == NULL) {
    abort();
  }
  int *new_end = new_begin + (position - begin);
  *new_end = *value;
  if (size > 0) {
    memcpy(new_begin, begin, size * sizeof(int));
  }
  int *new_capacity = new_begin + new_size;
  free(begin);
  this->data->impl->begin = new_begin;
  this->data->impl->end = new_end + 1;
  this->data->impl->capacity = new_capacity;
}

void _Z1fi(struct std_vector *this, int n) {
  int i;
  for (i = 0; i < n; i++) {
    _ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_(this, this->data->impl->end, &i);
  }
}


```
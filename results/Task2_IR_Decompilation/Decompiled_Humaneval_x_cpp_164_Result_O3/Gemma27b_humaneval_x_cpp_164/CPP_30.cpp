```c
#include <stdlib.h>

typedef struct {
  float *begin_;
  float *end_;
  float *capacity_;
} std_vector;

void get_positive(std_vector *dest, const std_vector *src) {
  dest->begin_ = NULL;
  dest->end_ = dest->begin_;
  dest->capacity_ = dest->begin_;
  float *src_begin = src->end_;
  float *src_end = src->begin_;
  if (src_begin == src_end) {
    return;
  }
  float *dest_begin = NULL;
  float *dest_end = NULL;
  float *dest_capacity = NULL;
  float *temp_begin = NULL;
  float *temp_end = NULL;
  float *temp_capacity = NULL;
  long long i = 0;
  for (; src_begin != src_end; ++src_begin) {
    if (*src_begin > 0.0f) {
      if (temp_end == temp_capacity) {
        long long temp_size = temp_end - temp_begin;
        long long new_size = temp_size == 0 ? 1 : temp_size * 2;
        float *new_allocation = (float *)malloc(new_size * sizeof(float));
        if (temp_begin != NULL) {
          for (long long j = 0; j < temp_size; ++j) {
            new_allocation[j] = temp_begin[j];
          }
          free(temp_begin);
        }
        temp_begin = new_allocation;
        temp_end = temp_begin + temp_size;
        temp_capacity = temp_begin + new_size;
      }
      *temp_end = *src_begin;
      ++temp_end;
    }
  }

  dest->begin_ = temp_begin;
  dest->end_ = temp_end;
  dest->capacity_ = temp_capacity;
}

```
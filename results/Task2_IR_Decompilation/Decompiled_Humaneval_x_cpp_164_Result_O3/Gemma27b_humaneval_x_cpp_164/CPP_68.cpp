```c
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
  int *data;
  size_t size;
  size_t capacity;
} vector_int_t;

void pluck_vector_int(vector_int_t *dest, const vector_int_t *src) {
  int *temp = (int *)malloc(sizeof(int) * 2);
  if (src->size == 0) {
    dest->size = 0;
    dest->capacity = 0;
    dest->data = NULL;
    return;
  }

  dest->data = temp;
  dest->size = 0;
  dest->capacity = 2;

  int *src_ptr = src->data;
  int *dest_ptr = dest->data;
  for (size_t i = 0; i < src->size; i++) {
    if ((*src_ptr & 1) == 0) {
      if (dest->size == dest->capacity) {
        dest->capacity *= 2;
        int *new_data = (int *)realloc(dest->data, sizeof(int) * dest->capacity);
        if (new_data == NULL) {
          free(dest->data);
          dest->size = 0;
          dest->capacity = 0;
          dest->data = NULL;
          return;
        }
        dest->data = new_data;
        dest_ptr = dest->data + dest->size;
      }
      *dest_ptr = *src_ptr;
      dest->size++;
      dest_ptr++;
    }
    src_ptr++;
  }
}

```
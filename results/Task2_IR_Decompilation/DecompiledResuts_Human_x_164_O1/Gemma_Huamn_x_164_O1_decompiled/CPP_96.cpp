```c
#include <stdlib.h>
#include <string.h>

typedef struct std_vector {
  int *data;
  int size;
  int capacity;
} std_vector;

void _Z11count_up_toi(std_vector *v, int n) {
  int i;
  v->data = NULL;
  v->size = 0;
  v->capacity = 0;
  i = 2;
  if (n > 2) {
    while (i < n) {
      int *p = v->data;
      int *q = p;
      int s = v->size;
      int c = v->capacity;
      if (p == q) {
        c = 0;
      } else {
        while (q != p) {
          c++;
          q++;
        }
      }
      if (s > c) {
        c = s;
      }
      int j;
      for (j = 0; j < c; j++) {
        if (i % (p[j] * p[j]) == 0) {
          break;
        }
      }
      if (j == c) {
        if (p == v->data && v->capacity == 0) {
          v->data = (int *)malloc(sizeof(int) * 1);
          v->capacity = 1;
        } else if (v->size == v->capacity) {
          int *new_data = (int *)malloc(sizeof(int) * (v->capacity * 2));
          memcpy(new_data, v->data, sizeof(int) * v->size);
          free(v->data);
          v->data = new_data;
          v->capacity *= 2;
        }
        v->data[v->size] = i;
        v->size++;
      }
      i++;
    }
  }
}
```
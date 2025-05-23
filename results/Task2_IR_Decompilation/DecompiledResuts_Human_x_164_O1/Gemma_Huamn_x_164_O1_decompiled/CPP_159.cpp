```c
#include <stdlib.h>

typedef struct {
  int *data;
  int *end;
  int *capacity;
} vec;

void eatiii(vec *v, int a, int b, int c) {
  if (c < b) {
    v->data = (int *)malloc(8);
    v->end = v->data + 1;
    v->capacity = v->data + 1;
    *v->data = a + c;
  } else {
    v->data = (int *)malloc(8);
    v->end = v->data + 1;
    v->capacity = v->data + 1;
    *v->data = b + a;
  }
}
```
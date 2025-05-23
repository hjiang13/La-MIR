```c
#include <stdlib.h>

typedef struct vector {
  int* data;
  int* end;
  int* capacity;
} vector;

void make_a_pile(vector* v, int size) {
  v->data = (int*)malloc(sizeof(int));
  v->end = v->data + 1;
  v->capacity = v->end;
  *v->data = size;
  int i;
  for (i = 1; i < size; i++) {
    int* new_data = (int*)malloc(sizeof(int) * (i + 1));
    int* new_end = new_data + i;
    int* new_capacity = new_data + (i + 1);
    for (int j = 0; j < i; j++) {
      new_data[j] = v->data[j];
    }
    new_data[i] = size;
    free(v->data);
    v->data = new_data;
    v->end = new_end;
    v->capacity = new_capacity;
  }
}
```

<|im_end|>
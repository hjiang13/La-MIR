```c
#include <stdlib.h>

typedef struct {
  int *data;
  int size;
  int capacity;
} vector;

void trii(vector *out, int n) {
  out->data = (int *)malloc(8);
  out->data[0] = 1;
  out->data[1] = 3;
  if (n == 0) {
    out->size = 0;
    out->capacity = 0;
    return;
  }
  if (n < 2) {
    out->size = n;
    out->capacity = 2;
    return;
  }
  int *tmp = malloc(sizeof(int) * (n + 1));
  tmp[0] = 1;
  tmp[1] = 3;
  int i = 2;
  for (; i < n; ++i) {
    tmp[i] = tmp[i - 1] + tmp[i - 2];
  }
  free(out->data);
  out->data = tmp;
  out->size = n;
  out->capacity = n;
}
```
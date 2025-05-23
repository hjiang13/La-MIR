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


#undef NDEBUG
#include<assert.h>
bool issame(vector<int> a,vector<int>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
        if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    assert (issame(pluck({4,2,3}) , {2, 1}));
    assert (issame(pluck({1,2,3}) , {2, 1}));
    assert (issame(pluck({}) , {}));
    assert (issame(pluck({5, 0, 3, 0, 4, 2}) , {0, 1}));
    assert (issame(pluck({1, 2, 3, 0, 5, 3}) , {0, 3}));
    assert (issame(pluck({5, 4, 8, 4 ,8}) , {4, 1}));
    assert (issame(pluck({7, 6, 7, 1}) , {6, 1}));
    assert (issame(pluck({7, 9, 7, 1}) , {}));
}

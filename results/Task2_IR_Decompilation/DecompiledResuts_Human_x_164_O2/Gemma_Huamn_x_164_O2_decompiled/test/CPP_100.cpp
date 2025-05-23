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
    assert (issame(make_a_pile(3) , {3, 5, 7}));
    assert (issame(make_a_pile(4) , {4,6,8,10}));
    assert (issame(make_a_pile(5) , {5, 7, 9, 11, 13}));
    assert (issame(make_a_pile(6) , {6, 8, 10, 12, 14, 16}));
    assert (issame(make_a_pile(8) , {8, 10, 12, 14, 16, 18, 20, 22}));
}

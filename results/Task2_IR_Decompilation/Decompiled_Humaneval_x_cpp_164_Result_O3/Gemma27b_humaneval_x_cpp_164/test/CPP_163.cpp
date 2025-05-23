#include <stdlib.h>
#include <string.h>

typedef struct {
  int *data;
  int *begin;
  int *end;
} vector_t;

void generate_integer(vector_t *v, int a, int b) {
  int max = (a < b) ? b : a;
  int min = (a < b) ? a : b;
  v->begin = v->end = v->data = 0;
  memset(v, 0, sizeof(vector_t));
  for (int i = min; i < max; ++i) {
    size_t size = (v->end - v->data);
    if (size == 0) {
      v->data = malloc(sizeof(int));
      v->begin = v->end = v->data;
    } else if (size == 1) {
      v->data = realloc(v->data, sizeof(int) * 2);
      v->end = v->data + 2;
    } else {
      size_t new_size = size * 2;
      v->data = realloc(v->data, sizeof(int) * new_size);
      v->end = v->data + new_size;
    }
    v->end[0] = i;
    v->end++;
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
    assert (issame(generate_integers(2, 10) , {2, 4, 6, 8}));
    assert (issame(generate_integers(10, 2) , {2, 4, 6, 8}));
    assert (issame(generate_integers(132, 2) , {2, 4, 6, 8}));
    assert (issame(generate_integers(17,89) , {}));
}

#include <stdlib.h>

typedef struct {
  int * _M_elems;
  int * _M_end_of_storage;
  int * _M_start;
} std_vector;

std_vector generate_integersii(int a, int b) {
  std_vector v = {NULL, NULL, NULL};
  int max = (a < b) ? b : a;
  int min = (a < b) ? a : b;

  for (int i = min; i < max; i++) {
    if (v._M_elems == NULL) {
      v._M_elems = (int*)malloc(sizeof(int) * 10);
      v._M_start = v._M_elems;
      v._M_end_of_storage = v._M_elems + 10;
    } else if (v._M_end_of_storage == v._M_elems) {
      int* tmp = (int*)malloc(sizeof(int) * ((v._M_end_of_storage - v._M_start) * 2));
      for (int j = 0; j < v._M_end_of_storage - v._M_start; j++) {
        tmp[j] = v._M_start[j];
      }
      free(v._M_start);
      v._M_start = tmp;
      v._M_elems = tmp;
      v._M_end_of_storage = tmp + ((v._M_end_of_storage - v._M_start) * 2);
    }
    v._M_elems[i - min] = i;
    v._M_elems++;
  }
  return v;
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
    assert (issame(generate_integers(2, 10) , {2, 4, 6, 8}));
    assert (issame(generate_integers(10, 2) , {2, 4, 6, 8}));
    assert (issame(generate_integers(132, 2) , {2, 4, 6, 8}));
    assert (issame(generate_integers(17,89) , {}));
}

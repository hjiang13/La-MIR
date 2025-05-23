#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _Z1fi(struct std::vector* noalias sret, int i32_1) {
  struct std::_Vector_base* base = (struct std::_Vector_base*)sret;
  int* begin = (int*)base->_M_impl._M_start;
  int* end = (int*)base->_M_impl._M_finish;
  int* capacity = (int*)base->_M_impl._M_end_of_storage;
  int size = end - begin;

  if (i32_1 < 1) {
    return;
  }

  while (size < i32_1) {
    if (size == 0) {
      begin = (int*)malloc(sizeof(int));
      end = begin + 1;
      capacity = end;
    } else {
      int new_size = size * 2;
      int* new_begin = (int*)malloc(new_size * sizeof(int));
      memcpy(new_begin, begin, size * sizeof(int));
      free(begin);
      begin = new_begin;
      end = begin + new_size;
      capacity = end;
    }
    size++;
  }

  for (int i = 0; i < i32_1; i++) {
    begin[i] = i + 1;
  }
}

int main() {
  struct std::vector* vec = (struct std::vector*)malloc(sizeof(struct std::vector));
  _Z1fi(vec, 10);
  return 0;
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
    assert (issame(f(5) , {1, 2, 6, 24, 15}));
    assert (issame(f(7) , {1, 2, 6, 24, 15, 720, 28}));
    assert (issame(f(1) , {1}));
    assert (issame(f(3) , {1, 2, 6}));
}

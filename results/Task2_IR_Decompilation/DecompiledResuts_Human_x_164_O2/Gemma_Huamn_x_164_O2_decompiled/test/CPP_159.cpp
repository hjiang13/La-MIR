#include <stdlib.h>

typedef struct {
  int* _M_start;
  int* _M_finish;
  int* _M_end_of_storage;
} _Vector_impl_data;

typedef struct {
  _Vector_impl_data _M_impl;
} _Vector_base;

typedef struct {
  _Vector_base _M_impl;
} vector;

void eati(vector* v, int a, int b, int c) {
  if (c < b) {
    v->_M_impl._M_impl._M_start = (int*)malloc(8);
    v->_M_impl._M_impl._M_finish = v->_M_impl._M_impl._M_start + (a + c);
    v->_M_impl._M_impl._M_end_of_storage = v->_M_impl._M_impl._M_finish;
    *v->_M_impl._M_impl._M_start = a + c;
    v->_M_impl._M_impl._M_start = v->_M_impl._M_impl._M_start + 4;
  } else {
    v->_M_impl._M_impl._M_start = (int*)malloc(8);
    v->_M_impl._M_impl._M_finish = v->_M_impl._M_impl._M_start + (b + a);
    v->_M_impl._M_impl._M_end_of_storage = v->_M_impl._M_impl._M_finish;
    *v->_M_impl._M_impl._M_start = b + a;
    v->_M_impl._M_impl._M_start = v->_M_impl._M_impl._M_start + 4;
  }
  *v->_M_impl._M_impl._M_start = c < b ? 0 : c - b;
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
    assert (issame(eat(5, 6, 10) , {11, 4}));
    assert (issame(eat(4, 8, 9) , {12, 1}));
    assert (issame(eat(1, 10, 10) , {11, 0}));
    assert (issame(eat(2, 11, 5) , {7, 0}));
    
    assert (issame(eat(4, 5, 7) , {9, 2}));
    assert (issame(eat(4, 5, 1) , {5, 0}));
}

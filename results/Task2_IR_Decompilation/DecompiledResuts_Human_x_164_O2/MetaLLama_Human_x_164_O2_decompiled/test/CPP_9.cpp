#include <stdlib.h>
#include <string.h>

typedef struct {
  int* _M_impl;
} _Vector_base;

typedef struct {
  int* _M_start;
  int* _M_finish;
  int* _M_end_of_storage;
} _Vector_impl_data;

typedef struct {
  _Vector_impl_data _M_impl;
} _Vector_base_int;

typedef struct {
  _Vector_base _M_base;
} vector;

void _Z11rolling_maxSt6vectorIiSaIiEE(vector* __result, vector* __x) {
  memset(__result, 0, sizeof(vector));
  int* __first = __x->_M_base._M_impl._M_start;
  int* __last = __x->_M_base._M_impl._M_finish;
  int* __result_start = __result->_M_base._M_impl._M_start;
  int* __result_finish = __result->_M_base._M_impl._M_finish;
  int* __result_end_of_storage = __result->_M_base._M_impl._M_end_of_storage;
  int __max = 0;
  int __val;

  if (__first == __last) {
    return;
  }

  while (1) {
    __val = *__first;
    if (__val > __max) {
      __max = __val;
    }
    ++__first;
    if (__first == __last) {
      break;
    }
  }

  __result_start = malloc(sizeof(int));
  *__result_start = __max;
  __result_finish = __result_start + 1;
  __result_end_of_storage = __result_finish;

  __result->_M_base._M_impl._M_start = __result_start;
  __result->_M_base._M_impl._M_finish = __result_finish;
  __result->_M_base._M_impl._M_end_of_storage = __result_end_of_storage;
}

void _ZdlPv(void* __p) {
  free(__p);
}

void _ZSt20__throw_length_errorPKc(const char* __msg) {
  // This function is not implemented, as it is not necessary for this example
}

void* _Znwm(size_t __size) {
  return malloc(__size);
}

void llvm_memmove_p0i8_p0i8_i64(void* __dest, const void* __src, size_t __size) {
  memmove(__dest, __src, __size);
}

void llvm_memset_p0i8_i64(void* __dest, int __val, size_t __size) {
  memset(__dest, __val, __size);
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
     assert (issame(rolling_max({}),{}));
    assert (issame(rolling_max({1, 2, 3, 4}) , {1, 2, 3, 4}));
     assert (issame(rolling_max({4, 3, 2, 1}),{4, 4, 4, 4}));
      assert (issame(rolling_max({3, 2, 3, 100, 3}) ,{3, 3, 3, 100, 100}));
}
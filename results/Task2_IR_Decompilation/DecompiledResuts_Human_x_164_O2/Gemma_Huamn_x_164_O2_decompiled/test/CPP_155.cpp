#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct std__cxx11__basic_string {
  struct std__cxx11__basic_string__Alloc_hider _M_dataplus;
  size_t _M_len;
  char *_M_data;
} std__cxx11__basic_string;

typedef struct _Vector_base {
  struct _Vector_base__Vector_impl_data _M_impl;
} _Vector_base;

typedef struct _Vector_base__Vector_impl_data {
  int * _M_start;
  int * _M_finish;
  int * _M_end_of_storage;
} _Vector_base__Vector_impl_data;

typedef struct __va_list_tag {
  int gp_offset;
  int fp_offset;
  void *overflow_arg_area;
  void *reg_save_area;
} __va_list_tag;

int llvm_abs(int x, int y) {
  return x < 0 ? -x : x;
}

void llvm_memset(void *dest, int c, size_t n) {
  memset(dest, c, n);
}

int llvm_vector_reduce_add_v4i32(__m128i x) {
  return x[0] + x[1] + x[2] + x[3];
}

void _ZN9__gnu_cxx12__to_xstringINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEcEET_PFiPT0_mPKS8_P13__va_list_tagEmSB_z(std__cxx11__basic_string *output, int (*func)(char *, size_t, char *, __va_list_tag *), size_t size, char *format, ...) {
  va_list args;
  va_start(args);
  int len = func(output->_M_data, size, format, &args);
  va_end(args);
  output->_M_len = len;
  output->_M_dataplus._M_p = output->_M_data + len;
}

void _Z14even_odd_counti(std__cxx11__basic_string *output, int input) {
  int abs_input = llvm_abs(input, 0);
  char buffer[32];
  sprintf(buffer, "%d", abs_input);
  _ZN9__gnu_cxx12__to_xstringINSt7__
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
    assert (issame(even_odd_count(7) , {0, 1}));
    assert (issame(even_odd_count(-78) , {1, 1}));
    assert (issame(even_odd_count(3452) , {2, 2}));
    assert (issame(even_odd_count(346211) , {3, 3}));
    assert (issame(even_odd_count(-345821) , {3, 3}));
    assert (issame(even_odd_count(-2) , {1, 0}));
    assert (issame(even_odd_count(-45347) , {2, 3}));
    assert (issame(even_odd_count(0) , {1, 0}));
}

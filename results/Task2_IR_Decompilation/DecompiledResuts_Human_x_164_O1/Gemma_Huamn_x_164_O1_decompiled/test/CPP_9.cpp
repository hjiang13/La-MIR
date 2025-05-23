#include <stdlib.h>

struct __gnu_cxx____normal_iterator {
};

struct std__vector {
  struct std____Vector_base {
    struct std____Vector_base___Vector_impl {
      struct std____Vector_base___Vector_impl___Vector_impl_data {
        int * __begin_;
        int * __end_;
        int * __end_cap_;
      } _M_impl;
    } _M_impl;
  } _M_impl;
};

void rolling_max(struct std__vector * __result, const struct std__vector * __arg) {
  int __tmp1;
  int * __tmp2;
  int * __tmp3;
  int * __tmp4;
  int * __tmp5;
  int * __tmp6;
  int * __tmp7;
  int * __tmp8;
  int * __tmp9;
  int * __tmp10;
  int * __tmp11;

  __tmp1 = 0;
  __tmp2 = (int *) 0;
  __tmp3 = (int *) 0;
  __tmp4 = __arg->_M_impl._M_impl._M_impl._M_begin_;
  __tmp5 = __arg->_M_impl._M_impl._M_impl._M_end_;
  __tmp6 = __result->_M_impl._M_impl._M_impl._M_begin_;
  __tmp7 = __result->_M_impl._M_impl._M_impl._M_end_;
  __tmp8 = __result->_M_impl._M_impl._M_impl._M_end_cap_;

  if (__tmp4 == __tmp5) {
    goto _loop_exit;
  }

_loop_start:
  __tmp9 = __tmp4;
  __tmp10 = __tmp9;
  __tmp11 = __tmp10 + 1;
  __tmp1 = *__tmp10;

  if (__tmp1 > __tmp1) {
    __tmp1 = __tmp1;
  }

  __tmp6 = __tmp6;
  __tmp7 = __tmp6 + 1;
  *__tmp6 = __tmp1;
  __tmp4 = __tmp11;
  if (__tmp4 != __tmp5) {
    goto _loop_start;
  }

_loop_exit:

  return;
}

void _ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_(struct std__vector * __this, int * __pos, int * __value) {
  int * __tmp12;
  int * __tmp13;
  int * __tmp14;
  int * __tmp15;
  int * __tmp16;
  long long __tmp17;
  long long __tmp18;
  long long __tmp19;
  long long __tmp20;
  int * __tmp21;
  int * __tmp22;
  long long __tmp23;
  int * __tmp24;
  int * __tmp25;
  int * __tmp26;
  int * __tmp27;
  int * __tmp28;
  long long __tmp29;
  long long __tmp30;

  __tmp12 = __this->_M_impl._M_impl._M_impl._M_end_;
  __tmp13 = __this->_M_impl._M_impl._M_impl._M_begin_;
  __tmp14 = __this->_M_impl._M_impl._M_impl._M_end_cap_;

  __tmp17 = (long long) __tmp12 - (long long) __tmp13;
  __tmp18 = __tmp17 / 4;
  __tmp19 = __tmp18;

  if (__tmp17 == 9223372036854775804) {
    abort();
  }

  if (__tmp17 == 0) {
    __tmp20 = 1;
  } else {
    __tmp20 = __tmp19;
  }

  __tmp21 = __pos;
  __tmp22 = __this->_M_impl._M_impl._M_impl._M_begin_;
  __tmp23 = (long long) __tmp21 - (long long) __tmp22;
  __tmp24 = __this->_M_impl._M_impl._M_impl._M_begin_;
  __tmp25 = __this->_M_impl._M_impl._M_impl._M_end_;

  if (__tmp20 == 0) {
    __tmp26 = (int *) 0;
  } else {
    if (__tmp20 > 2305843009213693951) {
      abort();
    }

    __tmp27 = (int *) malloc(__tmp20 * 4);
    __tmp26 = __tmp27;
  }

  __tmp28 = __tmp26;
  __tmp29 = __tmp23;
  *__tmp28 = *__value;

  if (__tmp23 > 0) {
    memcpy(__tmp26, __tmp24, __tmp23 * 4);
  }

  __tmp30 = (long long) __tmp25 - (long long) __tmp21;
  if (__tmp30 > 0) {
    memcpy(__tmp26 + __tmp29 + 1, __tmp21, __tmp30 * 4);
  }

  if (__tmp24 != (int *) 0) {
    free(__tmp24);
  }

  __this->_M_impl._M_impl._M_impl._M_begin_ = __tmp26;
  __this->_M_impl._M_impl._M_impl._M_end_ = __tmp26 + __tmp29 + 1;
  __this->_M_impl._M_impl._M_impl._M_end_cap_ = __tmp26 + __tmp20;

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
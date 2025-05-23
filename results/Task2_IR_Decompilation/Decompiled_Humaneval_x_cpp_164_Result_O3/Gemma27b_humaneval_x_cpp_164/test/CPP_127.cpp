#include <stdint.h>

struct std__cxx11__basic_string {
  struct std__cxx11__basic_string__Alloc_hider _Alloc_hider;
  int64_t _M_length;
  union anon _M_data;
};

struct std__cxx11__basic_string__Alloc_hider {
  char* _M_p;
};

union anon {
  int64_t _M_data_size;
  char _M_data_array[8];
};

struct std__vector {
  struct std__vector__Vector_base _M_impl;
};

struct std__vector__Vector_base {
  struct std__vector__Vector_base__Vector_impl _M_impl;
};

struct std__vector__Vector_base__Vector_impl {
  struct std__vector__Vector_base__Vector_impl_data _M_data;
};

struct std__vector__Vector_base__Vector_impl_data {
  int32_t* _M_start;
  int32_t* _M_finish;
  int32_t* _M_end_of_storage;
};

extern const char .str.1[4];

void intersectionB5cxx11St6vectorIiSaIiEES1_(struct std__cxx11__basic_string* __result, struct std__vector* __x, struct std__vector* __y) {
  int32_t* x_begin = (*__x)._M_impl._M_impl._M_data._M_start;
  int32_t* y_begin = (*__y)._M_impl._M_impl._M_data._M_start;
  int32_t x_size = (*x_begin);
  int32_t y_size = (*y_begin);
  int32_t min_size = (x_size < y_size) ? y_size : x_size;
  x_begin++;
  y_begin++;
  int32_t max_size = (*x_begin < *y_begin) ? *y_begin : *x_begin;
  x_begin++;
  y_begin++;
  int32_t diff = max_size - min_size;
  if (diff < 2) {
    (*__result)._M_Alloc_hider._M_p = (char*) &(*__result)._M_data;
    *((int16_t*) (*__result)._M_Alloc_hider._M_p) = 20302;
    (*__result)._M_length = 2;
    (*__result)._M_Alloc_hider._M_p[2] = 0;
    return;
  }
  if (diff < 4) {
    (*__result)._M_Alloc_hider._M_p = (char*) &(*__result)._M_data;
    
    memcpy((*__result)._M_Alloc_hider._M_p, "YES", 3);
    (*__result)._M_length = 3;
    (*__result)._M_Alloc_hider._M_p[3] = 0;
    return;
  }
  int32_t size = diff * diff;
  if (size > diff) {
    (*__result)._M_Alloc_hider._M_p = (char*) &(*__result)._M_data;
    
    memcpy((*__result)._M_Alloc_hider._M_p, "YES", 3);
    (*__result)._M_length = 3;
    (*__result)._M_Alloc_hider._M_p[3] = 0;
    return;
  }
  int32_t i;
  for (i = 2; (diff % i) != 0; ++i)
    ;
  (*__result)._M_Alloc_hider._M_p = (char*) &(*__result)._M_data;
 
  memcpy((*__result)._M_Alloc_hider._M_p, "YES", 3);
  (*__result)._M_length = 3;
  (*__result)._M_Alloc_hider._M_p[3] = 0;
  return;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (intersection({1, 2}, {2, 3}) == "NO");
    assert (intersection({-1, 1}, {0, 4}) == "NO");
    assert (intersection({-3, -1}, {-5, 5}) == "YES");
    assert (intersection({-2, 2}, {-4, 0}) == "YES");
    assert (intersection({-11, 2}, {-1, -1}) == "NO");
    assert (intersection({1, 2}, {3, 5}) == "NO");
    assert (intersection({1, 2}, {1, 2}) == "NO");
    assert (intersection({-2, -2}, {-3, -2}) == "NO");
}

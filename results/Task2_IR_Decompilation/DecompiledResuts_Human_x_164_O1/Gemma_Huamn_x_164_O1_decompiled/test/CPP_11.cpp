#include <string.h>

struct std__cxx11__basic_string {
  struct std__cxx11__basic_string___Alloc_hider _Alloc_hider;
  long long _M_length;
  union anon _M_dataplus;
};

struct std__cxx11__basic_string___Alloc_hider {
  char* _M_p;
};

union anon {
  long long _M_string_length;
  char _M_local_buf[8];
};

void string_xor(struct std__cxx11__basic_string* __dest, const struct std__cxx11__basic_string* __s1, const struct std__cxx11__basic_string* __s2) {
  struct std__cxx11__basic_string* __s = __dest;
  __s->_M_dataplus = &(__s->_M_dataplus);
  __s->_M_length = 0;
  __s->_M_dataplus->_M_string_length = 0;
  long long __tmp = __s1->_M_length;
  if (__tmp == 0) {
    return;
  }
  long long __tmp2 = __s2->_M_length;
  if (__tmp2 > __tmp) {
    char* __s1_char = __s1->_M_dataplus->_M_string_length == 0 ? __s1->_M_dataplus._M_local_buf : __s1->_Alloc_hider._M_p;
    char* __s2_char = __s2->_M_dataplus->_M_string_length == 0 ? __s2->_M_dataplus._M_local_buf : __s2->_Alloc_hider._M_p;
    for (long long __i = 0; __i < __tmp; __i++) {
      char __c1 = __s1_char[__i];
      char __c2 = __s2_char[__i];
      if (__c1 == __c2) {
        long long __len = __s->_M_length;
        char* __dest_char = __s->_M_dataplus->_M_string_length == 0 ? __s->_M_dataplus._M_local_buf : __s->_Alloc_hider._M_p;

        if (__s->_M_dataplus->_M_string_length == 15) {
          __s->_M_dataplus->_M_string_length = 0;
          __s->_M_dataplus = (union anon*)realloc(__s->_M_dataplus, sizeof(union anon) + 16);
        }
        __dest_char[__len] = 48;
        __s->_M_length = __len + 1;
        __dest_char[__len + 1] = 0;

      } else {

        long long __len = __s->_M_length;
        char* __dest_char = __s->_M_dataplus->_M_string_length == 0 ? __s->_M_dataplus._M_local_buf : __s->_Alloc_hider._M_p;

        if (__s->_M_dataplus->_M_string_length == 15) {
          __s->_M_dataplus->_M_string_length = 0;
          __s->_M_dataplus = (union anon*)realloc(__s->_M_dataplus, sizeof(union anon) + 16);
        }
        __dest_char[__len] = 49;
        __s->_M_length = __len + 1;
        __dest_char[__len + 1] = 0;
      }
    }
  }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (string_xor("111000", "101010") == "010010");
     assert (string_xor("1", "1") == "0");
    assert (string_xor("0101", "0000") == "0101");

}

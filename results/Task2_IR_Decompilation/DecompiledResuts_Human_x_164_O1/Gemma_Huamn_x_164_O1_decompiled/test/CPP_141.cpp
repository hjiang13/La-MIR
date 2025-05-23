#include <stdlib.h>
#include <string.h>

struct _Alloc_hider {
  char* _M_p;
};

union anon {
  long _M_length;
  char _M_str[8];
};

struct basic_string {
  struct _Alloc_hider _M_dataplus;
  long _M_len;
  union anon _M_data;
};

void _Z15file_name_checkNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE(
    struct basic_string* __ret, struct basic_string* __s) {
  if (__s->_M_len < 5) {
    __ret->_M_dataplus._M_p = (char*) malloc(3);
    ((char*)(__ret->_M_dataplus._M_p))[0] = 28494;
    ((char*)(__ret->_M_dataplus._M_p))[1] = 28494;
    __ret->_M_len = 2;
    ((char*)(__ret->_M_dataplus._M_p))[2] = 0;
    return;
  }
  char* s = __s->_M_dataplus._M_p;
  if (s[0] < 65) {
    __ret->_M_dataplus._M_p = (char*) malloc(3);
    ((char*)(__ret->_M_dataplus._M_p))[0] = 28494;
    ((char*)(__ret->_M_dataplus._M_p))[1] = 28494;
    __ret->_M_len = 2;
    ((char*)(__ret->_M_dataplus._M_p))[2] = 0;
    return;
  }
  struct basic_string tmp;
  long len = __s->_M_len - 4;
  tmp._M_dataplus._M_p = (char*) malloc(len + 1);
  memcpy(tmp._M_dataplus._M_p, s + len, len);
  tmp._M_dataplus._M_p[len] = 0;
  tmp._M_len = len;

  if (strcmp(tmp._M_dataplus._M_p, ".txt") == 0) {
    __ret->_M_dataplus._M_p = (char*) malloc(3);
    ((char*)(__ret->_M_dataplus._M_p))[0] = 28494;
    ((char*)(__ret->_M_dataplus._M_p))[1] = 28494;
    __ret->_M_len = 2;
    ((char*)(__ret->_M_dataplus._M_p))[2] = 0;
  } else if (strcmp(tmp._M_dataplus._M_p, ".exe") == 0) {
    __ret->_M_dataplus._M_p = (char*) malloc(3);
    ((char*)(__ret->_M_dataplus._M_p))[0] = 28494;
    ((char*)(__ret->_M_dataplus._M_p))[1] = 28494;
    __ret->_M_len = 2;
    ((char*)(__ret->_M_dataplus._M_p))[2] = 0;
  } else if (strcmp(tmp._M_dataplus._M_p, ".dll") == 0) {
    __ret->_M_dataplus._M_p = (char*) malloc(3);
    ((char*)(__ret->_M_dataplus._M_p))[0] = 28494;
    ((char*)(__ret->_M_dataplus._M_p))[1] = 28494;
    __ret->_M_len = 2;
    ((char*)(__ret->_M_dataplus._M_p))[2] = 0;
  } else {
    __ret->_M_dataplus._M_p = (char*) malloc(4);
    ((char*)(__ret->_M_dataplus._M_p))[0] = 28494;
    ((char*)(__ret->_M_dataplus._M_p))[1] = 28494;
    ((char*)(__ret->_M_dataplus._M_p))[2] = 28494;
    __ret->_M_len = 3;
    ((char*)(__ret->_M_dataplus._M_p))[3] = 0;
  }
  free(tmp._M_dataplus._M_p);
}


#undef NDEBUG
#include<assert.h>
int main(){
    assert (file_name_check("example.txt") == "Yes");
    assert (file_name_check("1example.dll") == "No");
    assert (file_name_check("s1sdf3.asd") == "No");
    assert (file_name_check("K.dll") == "Yes");
    assert (file_name_check("MY16FILE3.exe") == "Yes");
    assert (file_name_check("His12FILE94.exe") == "No");
    assert (file_name_check("_Y.txt") == "No");
    assert (file_name_check("?aREYA.exe") == "No");
    assert (file_name_check("/this_is_valid.dll") == "No");
    assert (file_name_check("this_is_valid.wow") == "No");
    assert (file_name_check("this_is_valid.txt") == "Yes");
    assert (file_name_check("this_is_valid.txtexe") == "No");
    assert (file_name_check("#this2_i4s_5valid.ten") == "No");
    assert (file_name_check("@this1_is6_valid.exe") == "No");
    assert (file_name_check("this_is_12valid.6exe4.txt") == "No");
    assert (file_name_check("all.exe.txt") == "No");
    assert (file_name_check("I563_No.exe") == "Yes");
    assert (file_name_check("Is3youfault.txt") == "Yes");
    assert (file_name_check("no_one#knows.dll") == "Yes");
    assert (file_name_check("1I563_Yes3.exe") == "No");
    assert (file_name_check("I563_Yes3.txtt") == "No");
    assert (file_name_check("final..txt") == "No");
    assert (file_name_check("final132") == "No");
    assert (file_name_check("_f4indsartal132.") == "No");
    assert (file_name_check(".txt") == "No");
    assert (file_name_check("s.") == "No");
}

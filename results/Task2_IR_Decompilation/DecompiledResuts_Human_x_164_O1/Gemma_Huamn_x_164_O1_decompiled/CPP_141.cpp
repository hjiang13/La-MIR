```c
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

```
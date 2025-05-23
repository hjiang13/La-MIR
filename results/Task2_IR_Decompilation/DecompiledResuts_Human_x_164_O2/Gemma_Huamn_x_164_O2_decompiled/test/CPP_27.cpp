#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  void *__isa;
  char *__s;
  unsigned long long _M_len;
  unsigned long long _M_cap;
} _Alloc_hider;

typedef struct {
  _Alloc_hider _M_impl;
} basic_string;

void filp_case(basic_string *result, const basic_string *s) {
  int64_t i = 0;
  int64_t len = s->_M_impl._M_len;
  for (; i < len; i++) {
    char c = s->_M_impl.__s[i];
    if (c >= 'a' && c <= 'z') {
      c -= 32;
    } else if (c >= 'A' && c <= 'Z') {
      c += 32;
    }
    result->_M_impl.__s[i] = c;
  }
}

```
<|im_end|>
#undef NDEBUG
#include<assert.h>
int main(){
    assert (filp_case("") == "");
    assert (filp_case("Hello!") == "hELLO!");
    assert (filp_case("These violent delights have violent ends") == "tHESE VIOLENT DELIGHTS HAVE VIOLENT ENDS");
}

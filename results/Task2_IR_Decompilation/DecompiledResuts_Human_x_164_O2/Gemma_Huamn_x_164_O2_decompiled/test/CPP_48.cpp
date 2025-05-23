#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int _Z13is_palindromeNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE(
    const void *s) {
  int64_t _132;
  int64_t _136;
  char *_133;
  char *_135;
  char *_137;
  char *_139;

  _137 = (char *)malloc(32);
  _135 = (char *)s;
  _136 = strlen(_135);
  _133 = _137;

  if (_136 > 15) {
    _133 = (char *)realloc(_137, _136);
  }
  memcpy(_133, _135, _136);
  _133[_136] = 0;

  _139 = _133 + _136 - 1;

  _132 = _136;
  while (_132 > 0) {
    if (*_133 != *_139) {
      free(_133);
      return 0;
    }
    _133++;
    _139--;
    _132--;
  }
  free(_133);
  return 1;
}

```

<|im_end|>
#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_palindrome("") == true);
    assert (is_palindrome("aba") == true);
    assert (is_palindrome("aaaaa") == true);
    assert (is_palindrome("zbcd") == false);
    assert (is_palindrome("xywyx") == true);
    assert (is_palindrome("xywyz") == false);
    assert (is_palindrome("xywzx") == false);
}

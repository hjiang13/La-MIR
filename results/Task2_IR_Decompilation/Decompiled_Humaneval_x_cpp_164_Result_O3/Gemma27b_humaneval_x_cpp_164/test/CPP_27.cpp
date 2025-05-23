#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  void* _M_dataplus;
  size_t _M_allocated_capacity;
} _Alloc_hider;

typedef struct {
  _Alloc_hider _M_hider;
  size_t _M_length;

  char* _M_data;

} basic_string;

void filp_case(basic_string* s0, basic_string* s1) {
  int64_t i = 0;
  basic_string s2;
  s2._M_hider._M_dataplus = malloc(sizeof(char));
  s2._M_hider._M_allocated_capacity = 0;

  s2._M_length = 0;
  s2._M_data = (char*)s2._M_hider._M_dataplus;

  if (s1->_M_length != 0) {
    char* p = (char*)s1->_M_data;

    for (i = 0; i < s1->_M_length; i++) {
      char c = p[i];
      if (c >= 97 && c <= 122) {
        c -= 32;
      } else if (c >= 65 && c <= 90) {
        c += 32;
      }
      s2._M_hider._M_allocated_capacity = i + 1;
      s2._M_hider._M_dataplus = realloc(s2._M_hider._M_dataplus, s2._M_hider._M_allocated_capacity);
      s2._M_data = (char*)s2._M_hider._M_dataplus;

      s2._M_data[i] = c;
      s2._M_length = i + 1;
    }
  }
  s0->_M_hider._M_dataplus = malloc(sizeof(char) * s2._M_length);
  s0->_M_hider._M_allocated_capacity = s2._M_length;
  s0->_M_length = s2._M_length;
  s0->_M_data = (char*)s0->_M_hider._M_dataplus;
  memcpy(s0->_M_data, s2._M_data, s2._M_length);
  free(s2._M_hider._M_dataplus);

}

int main() {
  return 0;
}


#undef NDEBUG
#include<assert.h>
int main(){
    assert (filp_case("") == "");
    assert (filp_case("Hello!") == "hELLO!");
    assert (filp_case("These violent delights have violent ends") == "tHESE VIOLENT DELIGHTS HAVE VIOLENT ENDS");
}

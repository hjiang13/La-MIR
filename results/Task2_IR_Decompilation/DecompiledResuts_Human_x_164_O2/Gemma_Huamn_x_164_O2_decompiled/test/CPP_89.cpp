#include <stdlib.h>
#include <string.h>

typedef struct {
  void* _Alloc_hider;
  size_t _M_p;
  union {
    size_t _M_length;
    char _M_bytes[8];
  };
} _Alloc_hider;

typedef struct {
  _Alloc_hider _M_dataplus;
  size_t _M_string_length;
} basic_string;

void encrypt(basic_string* s, const basic_string* key) {
  size_t i = 0;
  size_t key_len = key->_M_string_length;
  if (key_len == 0) {
    return;
  }
  for (; i < key_len; ++i) {
    char c = key->_M_dataplus._M_bytes[i];
    char encrypted_c = c - 93;
    encrypted_c %= 26;
    encrypted_c += 97;
    s->_M_dataplus._M_bytes[i] = encrypted_c;
  }
  s->_M_string_length = key_len;
}



int main() {
  basic_string s;
  basic_string key;
  
  encrypt(&s, &key);
  
  return 0;
}


#undef NDEBUG
#include<assert.h>
int main(){
    assert (encrypt("hi") == "lm");
    assert (encrypt("asdfghjkl") == "ewhjklnop");
    assert (encrypt("gf") == "kj");
    assert (encrypt("et") == "ix");
    assert (encrypt("faewfawefaewg")=="jeiajeaijeiak");
    assert (encrypt("hellomyfriend")=="lippsqcjvmirh");
    assert (encrypt("dxzdlmnilfuhmilufhlihufnmlimnufhlimnufhfucufh")=="hbdhpqrmpjylqmpyjlpmlyjrqpmqryjlpmqryjljygyjl");
    assert (encrypt("a")=="e");
}

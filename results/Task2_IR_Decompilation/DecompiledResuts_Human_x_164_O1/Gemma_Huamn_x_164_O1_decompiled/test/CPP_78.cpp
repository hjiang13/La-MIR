#include <stdint.h>

int hex_key(const char* s) {
  char t[7] = "2357BD";
  size_t l = 6;
  int i = 0;
  while (i < l) {
    if (s[i] == t[i]) {
      return 1;
    }
    i++;
  }
  return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (hex_key("AB") == 1      );
    assert (hex_key("1077E") == 2 );
    assert (hex_key("ABED1A33") == 4     );
    assert (hex_key("2020") == 2 );
    assert (hex_key("123456789ABCDEF0") == 6      );
    assert (hex_key("112233445566778899AABBCCDDEEFF00") == 12 );
    assert (hex_key("") == 0);
}

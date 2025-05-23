#include <stdint.h>

int hex_key(const char* str) {
  char key[32] = "2357BD";
  int len = 6;
  int i;
  int match = 0;

  if (strlen(str) == 0) {
    return 0;
  }

  for (i = 0; i < len; i++) {
    if (key[i] != str[i]) {
      return 0;
    }
  }

  return 1;
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

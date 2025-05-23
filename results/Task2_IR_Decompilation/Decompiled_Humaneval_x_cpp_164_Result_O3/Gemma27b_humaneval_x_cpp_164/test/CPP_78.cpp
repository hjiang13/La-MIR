#include <string>

int hex_key(const std::string& str) {
  std::string key = "2357BD";
  if (str.empty()) {
    return 0;
  }

  int count = 0;
  for (size_t i = 0; i < str.length(); ++i) {
    if (str[i] == key[0] ||
        str[i] == key[1] ||
        str[i] == key[2] ||
        str[i] == key[3] ||
        str[i] == key[4] ||
        str[i] == key[5]) {
      count++;
    }
  }

  return count;
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

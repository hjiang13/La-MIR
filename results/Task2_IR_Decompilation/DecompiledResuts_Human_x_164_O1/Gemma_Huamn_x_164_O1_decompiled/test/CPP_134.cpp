#include <stddef.h>

int check_if_last_char_is_a_letter(const char* s) {
  size_t len = strlen(s);
  if (len == 0) {
    return 0;
  }
  char c = s[len - 1];
  if (c < 'A' || c > 'Z') {
    if (c < 'a' || c > 'z') {
      return 0;
    }
  }
  return 1;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (check_if_last_char_is_a_letter("apple") == false);
    assert (check_if_last_char_is_a_letter("apple pi e") == true);
    assert (check_if_last_char_is_a_letter("eeeee") == false);
    assert (check_if_last_char_is_a_letter("A") == true);
    assert (check_if_last_char_is_a_letter("Pumpkin pie ") == false);
    assert (check_if_last_char_is_a_letter("Pumpkin pie 1") == false);
    assert (check_if_last_char_is_a_letter("") == false);
    assert (check_if_last_char_is_a_letter("eeeee e ") == false);
    assert (check_if_last_char_is_a_letter("apple pie") == false);
    assert (check_if_last_char_is_a_letter("apple pi e ") == false);
}

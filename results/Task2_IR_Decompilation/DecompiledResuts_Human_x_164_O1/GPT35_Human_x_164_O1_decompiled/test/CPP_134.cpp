```cpp
#include <string>

extern "C" bool check_if_last_char_is_a_letter(std::__cxx11::basic_string<char>* str) {
  if (str->size() == 0) {
    return false;
  }

  int64_t size = str->size();
  char* data = &(*str)[0];

  char last_char = data[size - 1];
  if (last_char < 'A') {
    return false;
  }

  if (last_char > 'Z') {
    if (last_char < 'a') {
      return false;
    }

    if (last_char > 'z') {
      return false;
    }
  }

  return true;
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

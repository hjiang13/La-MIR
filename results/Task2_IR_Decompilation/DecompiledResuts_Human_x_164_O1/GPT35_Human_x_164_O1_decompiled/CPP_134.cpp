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
```
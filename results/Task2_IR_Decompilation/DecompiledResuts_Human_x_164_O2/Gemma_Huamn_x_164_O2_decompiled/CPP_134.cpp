```c
#include <string>

bool check_if_last_char_is_a_letter(const std::string& str) {
  if (str.length() == 0) {
    return false;
  }
  size_t last_char_index = str.length() - 1;
  char last_char = str[last_char_index];
  if (last_char < 'A' || last_char > 'Z') {
    return false;
  }
  return true;
}
```
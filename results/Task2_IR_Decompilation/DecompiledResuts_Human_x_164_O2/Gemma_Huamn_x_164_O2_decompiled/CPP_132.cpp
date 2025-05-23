```c
#include <string>

bool is_nested(const std::string& str) {
  if (str.length() == 0) {
    return false;
  }
  char first_char = str[0];
  int open_brackets = 0;
  int close_brackets = 0;
  if (first_char == '[') {
    open_brackets++;
  } else if (first_char == ']') {
    close_brackets++;
  }
  for (size_t i = 1; i < str.length(); i++) {
    char current_char = str[i];
    if (current_char == '[') {
      open_brackets++;
    } else if (current_char == ']') {
      close_brackets++;
    }
    if (open_brackets > close_brackets) {
      return true;
    }
  }
  return false;
}
```
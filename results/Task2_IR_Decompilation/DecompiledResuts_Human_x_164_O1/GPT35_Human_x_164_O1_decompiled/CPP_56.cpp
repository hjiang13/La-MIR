```c++
#include <string>

bool correct_bracketing(std::__cxx11::basic_string<char> *str) {
  i64 size = str->__size_;
  if (size != 0) {
    char *data = str->__data_;
    char first_char = data[0];
    int open_brackets = (first_char == '<') ? 1 : 0;
    int close_brackets = (first_char == '>') ? 1 : 0;
    
    for (i64 i = 1; i < size; i++) {
      char current_char = data[i];
      if (current_char == '<') {
        open_brackets++;
      } else if (current_char == '>') {
        close_brackets++;
      }
      
      if (close_brackets > open_brackets) {
        return false;
      }
    }
    
    return open_brackets == close_brackets;
  }
  
  return true;
}
```
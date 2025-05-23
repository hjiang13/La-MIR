```cpp
#include <string>

bool is_nested(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>* str) {
  if (str->size() == 0)
    return false;

  int count = 0;
  bool nested = false;

  for (size_t i = 0; i < str->size(); ++i) {
    char c = (*str)[i];
    if (c == '[')
      count++;
    else if (c == ']')
      count--;

    if (count > 0)
      nested = true;
    if (count < 0)
      return false;
  }

  return nested;
}
```
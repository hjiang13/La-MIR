```cpp
#include <string>

bool is_palindrome(std::__cxx11::basic_string<char>* str) {
  std::__cxx11::basic_string<char> temp;
  if (str->size() > 15) {
    temp._M_create(0);
    temp[0] = str->back();
    for (int i = 1; i < str->size(); ++i) {
      temp[i] = str->at(str->size() - i - 1);
    }
  }

  return temp == *str;
}
```
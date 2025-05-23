```cpp
#include <string>

bool correct_bracketing(std::basic_string<char, std::char_traits<char>, std::allocator<char>>* arg) {
  int64_t size = arg->__getRep()->_M_length;
  if (size != 0) {
    char* data = arg->__getRep()->_M_dataplus._M_p;
    char current;
    int openCount = 0;
    int closeCount = 0;
    for (int64_t i = 0; i < size; i++) {
      current = data[i];
      if (current == '(') {
        openCount++;
      } else if (current == ')') {
        closeCount++;
      }
      if (closeCount > openCount) {
        return false;
      }
    }
    return openCount == closeCount;
  }
  return true;
}
```
Here is the decompiled C++ source code for the provided IR code:
```
#include <iostream>
#include <string>

using namespace std;

bool check_if_last_char_is_a_letter(string str) {
  if (str.length() == 0) {
    return false;
  }
  char lastChar = str[str.length() - 1];
  if (lastChar >= 'a' && lastChar <= 'z') {
    return true;
  }
  return false;
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original source code.
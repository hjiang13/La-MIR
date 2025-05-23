```cpp
#include <string>

int digitSum(std::basic_string<char> str) {
  int sum = 0;
  for (int i = 0; i < str.length(); i++) {
    char c = str[i];
    if (c >= 'A' && c <= 'Z') {
      sum += c;
    }
  }
  return sum;
}
```
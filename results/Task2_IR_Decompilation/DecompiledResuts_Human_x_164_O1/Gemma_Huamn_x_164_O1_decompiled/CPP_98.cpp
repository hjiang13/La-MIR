```c
#include <string>

int count_upper(const std::string& s) {
  std::string str = "AEIOU";
  int count = 0;
  for (size_t i = 0; i < s.length(); i++) {
    if (str.find(s[i]) != std::string::npos) {
      count++;
    }
  }
  return count;
}

```
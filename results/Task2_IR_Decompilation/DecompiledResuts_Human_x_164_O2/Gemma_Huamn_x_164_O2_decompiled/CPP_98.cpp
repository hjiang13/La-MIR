```c
#include <string>

int count_upper(const std::string& s) {
  std::string str = "AEIOU";
  if (s.size() == 0) {
    return 0;
  }
  int count = 0;
  for (size_t i = 0; i < s.size() / 2; ++i) {
    if (str[0] == s[i] || str[1] == s[i] || str[2] == s[i] || str[3] == s[i] || str[4] == s[i]) {
      count++;
    }
  }
  return count;
}
```
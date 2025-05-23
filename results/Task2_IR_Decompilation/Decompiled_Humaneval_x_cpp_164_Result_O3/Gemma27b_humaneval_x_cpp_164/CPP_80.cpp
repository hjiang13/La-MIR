```c
#include <string>

bool is_happy(const std::string& s) {
  if (s.size() < 3) {
    return false;
  }
  if (s[1] == s[2]) {
    return true;
  }
  for (size_t i = 2; i < s.size(); ++i) {
    if (s[i] == s[i - 2] && i > 2) {
      return true;
    }
  }
  return false;
}
```
```c
#include <string>

int hex_key(const std::string& str) {
  std::string key = "2357BD";
  if (str.empty()) {
    return 0;
  }

  int count = 0;
  for (size_t i = 0; i < str.length(); ++i) {
    if (str[i] == key[0] ||
        str[i] == key[1] ||
        str[i] == key[2] ||
        str[i] == key[3] ||
        str[i] == key[4] ||
        str[i] == key[5]) {
      count++;
    }
  }

  return count;
}

```
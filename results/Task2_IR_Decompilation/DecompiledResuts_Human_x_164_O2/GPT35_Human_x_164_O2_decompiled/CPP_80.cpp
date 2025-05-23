```cpp
#include <string>

bool is_happy(std::basic_string<char> &str) {
  size_t length = str.size();

  if (length < 3) {
    return false;
  }

  const char *data = str.data();
  char first = data[0];
  char second = data[1];

  for (size_t i = 2; i < length; ++i) {
    char current = data[i];
    if (current == first) {
      return false;
    }
    first = second;
    second = current;
  }

  return true;
}
```
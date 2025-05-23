```cpp
#include <string>

int is_bored(std::__cxx11::basic_string<char> &str) {
  if (str.size() == 0) {
    return 0;
  }

  int count = 0;
  int total = 0;
  int last_count = 0;
  char last_char = 1;

  for (size_t i = 0; i < str.size(); i++) {
    char current_char = str[i];

    if (current_char == ' ') {
      total += last_count;
      count = 0;
    } else {
      total += count;
      bool is_interesting = current_char == 'I' && last_char != 0;
      last_count = is_interesting ? 1 : 0;
    }

    switch (current_char) {
      case '.':
      case '?':
      case '!':
        break;
    }

    last_char = current_char;
  }

  return total;
}
```
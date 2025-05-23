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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_bored("Hello world") == 0);
    assert (is_bored("Is the sky blue?") == 0);
    assert (is_bored("I love It !") == 1);
    assert (is_bored("bIt") == 0);
    assert (is_bored("I feel good today. I will be productive. will kill It") == 2);
    assert (is_bored("You and I are going for a walk") == 0);
}

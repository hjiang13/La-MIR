#include <stdint.h>
#include <stddef.h>

int is_bored(const char* str) {
  size_t len = strlen(str);
  if (len == 0) {
    return 0;
  }
  int count = 0;
  int i = 0;
  int state = 1;
  for (; i < len; i++) {
    if (str[i] == ' ') {
      count += state;
    } else if (str[i] == 'I' && state) {
      count += 1;
      state = 0;
    } else {
      state = (str[i] == '.' || str[i] == '?' || str[i] == '!');
    }
  }
  return count;
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

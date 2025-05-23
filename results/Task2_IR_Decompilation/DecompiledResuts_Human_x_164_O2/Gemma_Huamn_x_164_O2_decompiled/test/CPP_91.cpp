int is_bored(const char* str) {
  int len = strlen(str);
  if (len == 0) {
    return 0;
  }

  int count = 0;
  int state = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] == ' ') {
      if (state == 1) {
        count++;
      }
      state = 0;
    } else if (str[i] == 'I') {
      if (state == 1) {
        count++;
      }
      state = 1;
    } else {
      state = 0;
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

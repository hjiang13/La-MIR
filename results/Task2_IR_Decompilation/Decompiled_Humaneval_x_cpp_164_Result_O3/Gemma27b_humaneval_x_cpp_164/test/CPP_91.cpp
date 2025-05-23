int is_bored(char* str) {
  long len = strlen(str);
  if (len == 0) {
    return 0;
  }

  int count = 0;
  int space_count = 0;

  for (long i = 0; i < len; i++) {
    if (str[i] == ' ') {
      if (space_count == 0) {
        space_count = 1;
      }
      count += space_count;
    } else if (str[i] == 'I') {
      if (space_count == 1) {
        count += 1;
      }
      space_count = 0;
    } else {
      space_count = 0;
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

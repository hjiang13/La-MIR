#include <stdint.h>

int vowels_count(const char* s) {
  char vowels[] = "aeiouAEIOU";
  int count = 0;
  for (size_t i = 0; i < strlen(s); i++) {
    for (size_t j = 0; j < 10; j++) {
      if (s[i] == vowels[j]) {
        count++;
        break;
      }
    }
  }
  return count;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (vowels_count("abcde") == 2);
    assert (vowels_count("Alone") == 3);
    assert (vowels_count("key") == 2);
    assert (vowels_count("bye") == 1);
    assert (vowels_count("keY") == 2);
    assert (vowels_count("bYe") == 1);
    assert (vowels_count("ACEDY") == 3);
   
}

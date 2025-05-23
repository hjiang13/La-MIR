#include <string.h>

int vowels_count(const std::string &s) {
  std::string vowels = "aeiouAEIOU";
  int count = 0;
  for (size_t i = 0; i < s.length(); ++i) {
    for (size_t j = 0; j < vowels.length(); ++j) {
      if (s[i] == vowels[j]) {
        count++;
        break;
      }
    }
  }
  if (s.length() > 0 && (s[s.length() - 1] == 'y' || s[s.length() - 1] == 'Y')) {
    count++;
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

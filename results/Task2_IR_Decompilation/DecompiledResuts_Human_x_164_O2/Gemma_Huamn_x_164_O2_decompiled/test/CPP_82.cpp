#include <stdint.h>

int prime_length(const char* s) {
  int64_t len = strlen(s);
  int32_t l = len;
  if (l < 2) return 0;
  if (l < 4) return 1;
  int32_t i = 2;
  while (1) {
    int32_t r = l % i;
    if (r == 0) {
      if (i * i > l) return 1;
    }
    i++;
  }
}


#undef NDEBUG
#include<assert.h>
int main(){
    assert (prime_length("Hello") == true);
    assert (prime_length("abcdcba") == true);
    assert (prime_length("kittens") == true);
    assert (prime_length("orange") == false);
    assert (prime_length("wow") == true);
    assert (prime_length("world") == true);
    assert (prime_length("MadaM") == true);
    assert (prime_length("Wow") == true);
    assert (prime_length("") == false);
    assert (prime_length("HI") == true);
    assert (prime_length("go") == true);
    assert (prime_length("gogo") == false);
    assert (prime_length("aaaaaaaaaaaaaaa") == false);
    assert (prime_length("Madam") == true);
    assert (prime_length("M") == false);
    assert (prime_length("0") == false);
}

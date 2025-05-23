#include <stdint.h>
#include <string.h>

int how_many_times(const char* s1, const char* s2) {
  if (strlen(s1) == 0) {
    return 0;
  }
  int count = 0;
  size_t len1 = strlen(s1);
  size_t len2 = strlen(s2);
  for (size_t i = 0; i < len1 - len2 + 1; i++) {
    if (strncmp(s1 + i, s2, len2) == 0) {
      count++;
    }
  }
  return count;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (how_many_times("", "x") == 0);
    assert (how_many_times("xyxyxyx", "x") == 4);
     assert (how_many_times("cacacacac", "cac") == 4);
    assert (how_many_times("john doe", "john") == 1);
}

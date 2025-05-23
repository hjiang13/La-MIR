#include <stdlib.h>

void string_xor(char **dest, const char *str1, const char *str2) {
  *dest = (char*)malloc(sizeof(char));

  long len1 = strlen(str1);
  long len2 = strlen(str2);
  long min_len = len1 < len2 ? len1 : len2;

  for (long i = 0; i < min_len; i++) {
    (*dest)[i] = str1[i] ^ str2[i];
  }

  (*dest)[min_len] = '\0';

  if (len1 > len2) {
    (*dest) = (char*)realloc((*dest), len1 + 1);
    for (long i = min_len; i < len1; i++) {
      (*dest)[i] = str1[i];
    }
  } else if (len2 > len1) {
    (*dest) = (char*)realloc((*dest), len2 + 1);
    for (long i = min_len; i < len2; i++) {
      (*dest)[i] = str2[i];
    }
  }

}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (string_xor("111000", "101010") == "010010");
     assert (string_xor("1", "1") == "0");
    assert (string_xor("0101", "0000") == "0101");

}

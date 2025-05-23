#include <stdint.h>
#include <stddef.h>

int count_upper(const char* str) {
  char target[] = "AEIOU";
  size_t target_len = 5;
  size_t len = strlen(str);

  if (len == 0) {
    return 0;
  }

  int count = 0;
  for (size_t i = 0; i < len; i++) {
    for (size_t j = 0; j < target_len; j++) {
      if (str[i] == target[j]) {
        count++;
        break;
      }
    }
  }

  return count;
}
```
<|im_end|>
#undef NDEBUG
#include<assert.h>
int main(){
    assert (count_upper("aBCdEf")  == 1);
    assert (count_upper("abcdefg") == 0);
    assert (count_upper("dBBE") == 0);
    assert (count_upper("B")  == 0);
    assert (count_upper("U")  == 1);
    assert (count_upper("") == 0);
    assert (count_upper("EEEE") == 2);
}

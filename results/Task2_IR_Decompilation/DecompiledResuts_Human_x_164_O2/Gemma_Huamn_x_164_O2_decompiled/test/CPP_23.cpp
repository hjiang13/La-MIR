#include <stdint.h>

int strlen(const char* str) {
  int len = 0;
  while (*str != '\0') {
    len++;
    str++;
  }
  return len;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (strlen("") == 0);
    assert (strlen("x") == 1);
     assert (strlen("asdasnakj") == 9);
}

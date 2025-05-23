#include <stdint.h>

int is_happy(const char *s) {
  if (strlen(s) < 3) {
    return 0;
  }
  if (s[2] == s[1]) {
    return 1;
  }
  for (size_t i = 2; i < strlen(s); i++) {
    if (s[i] == s[i - 2]) {
      return 1;
    }
  }
  return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_happy("a") == false );
    assert (is_happy("aa") == false );
    assert (is_happy("abcd") == true );
    assert (is_happy("aabb") == false );
    assert (is_happy("adb") == true );
    assert (is_happy("xyy") == false );
    assert (is_happy("iopaxpoi") == true );
    assert (is_happy("iopaxioi") == false );
}

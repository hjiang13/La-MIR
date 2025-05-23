#include <stdint.h>

bool is_happy(const char* str, size_t len) {
  if (len < 3) {
    return false;
  }

  char first = str[1];
  char second = str[2];
  if (second == first) {
    return true;
  }

  for (size_t i = 2; i < len; ++i) {
    if (str[i] == first && i > 2) {
      return true;
    }
    if (str[i] == second && i > 2) {
      return false;
    }
  }
  return true;
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

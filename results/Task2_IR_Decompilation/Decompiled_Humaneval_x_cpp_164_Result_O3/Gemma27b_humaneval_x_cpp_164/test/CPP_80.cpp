#include <string>

bool is_happy(const std::string& s) {
  if (s.size() < 3) {
    return false;
  }
  if (s[1] == s[2]) {
    return true;
  }
  for (size_t i = 2; i < s.size(); ++i) {
    if (s[i] == s[i - 2] && i > 2) {
      return true;
    }
  }
  return false;
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

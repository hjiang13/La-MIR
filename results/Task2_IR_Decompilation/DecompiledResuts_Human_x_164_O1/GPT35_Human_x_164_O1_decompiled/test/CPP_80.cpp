```cpp
#include <string>

bool is_happy(std::basic_string<char, std::char_traits<char>, std::allocator<char>>* str) {
  int64_t len = (*str)._M_rep()->_M_length;
  if (len < 3) {
    return false;
  } else {
    char* data = (*str)._M_rep()->_M_refdata;
    for (int64_t i = 0; i < len / 2; ++i) {
      if (data[i] != data[len - i - 1]) {
        return false;
      }
    }
    return true;
  }
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

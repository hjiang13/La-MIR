```cpp
#include <string>

bool is_happy(std::basic_string<char> &str) {
  size_t length = str.size();

  if (length < 3) {
    return false;
  }

  const char *data = str.data();
  char first = data[0];
  char second = data[1];

  for (size_t i = 2; i < length; ++i) {
    char current = data[i];
    if (current == first) {
      return false;
    }
    first = second;
    second = current;
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

```cpp
#include <string>

bool is_palindrome(std::__cxx11::basic_string<char>* str) {
  std::__cxx11::basic_string<char> temp;
  if (str->size() > 15) {
    temp._M_create(0);
    temp[0] = str->back();
    for (int i = 1; i < str->size(); ++i) {
      temp[i] = str->at(str->size() - i - 1);
    }
  }

  return temp == *str;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_palindrome("") == true);
    assert (is_palindrome("aba") == true);
    assert (is_palindrome("aaaaa") == true);
    assert (is_palindrome("zbcd") == false);
    assert (is_palindrome("xywyx") == true);
    assert (is_palindrome("xywyz") == false);
    assert (is_palindrome("xywzx") == false);
}

```cpp
#include <string>

bool is_nested(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>* str) {
  if (str->size == 0)
    return false;

  int count = 0;
  for (int i = 0; i < str->size; i++) {
    if (str->data[i] == '[')
      count++;
    else if (str->data[i] == ']')
      count--;

    if (count > 0)
      return true;
  }

  return false;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_nested("[[]]") == true);
    assert (is_nested("[]]]]]]][[[[[]") == false);
    assert (is_nested("[][]") == false);
    assert (is_nested(("[]")) == false);
    assert (is_nested("[[[[]]]]") == true);
    assert (is_nested("[]]]]]]]]]]") == false);
    assert (is_nested("[][][[]]") == true);
    assert (is_nested("[[]") == false);
    assert (is_nested("[]]") == false);
    assert (is_nested("[[]][[") == true);
    assert (is_nested("[[][]]") == true);
    assert (is_nested("") == false);
    assert (is_nested("[[[[[[[[") == false);
    assert (is_nested("]]]]]]]]") == false);
}

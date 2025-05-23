#include <string>

bool correct_bracketing(std::basic_string<char, std::char_traits<char>, std::allocator<char>>* arg) {
  int64_t size = arg->__s.__size_;
  if (size == 0)
    return true;

  char* data = arg->__s.__data_;
  int32_t count = 0;
  for (int64_t i = 0; i < size; i++) {
    char c = data[i];
    if (c == '(')
      count++;
    else if (c == ')')
      count--;

    if (count < 0)
      return false;
  }

  return count == 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (correct_bracketing("()"));
    assert (correct_bracketing("(()())"));
    assert (correct_bracketing("()()(()())()"));
    assert (correct_bracketing("()()((()()())())(()()(()))"));
    assert (not (correct_bracketing("((()())))")));
    assert (not (correct_bracketing(")(()")));
    assert (not (correct_bracketing("(")));
    assert (not (correct_bracketing("((((")));
    assert (not (correct_bracketing(")")));
    assert (not (correct_bracketing("(()")));
    assert (not (correct_bracketing("()()(()())())(()")));
    assert (not (correct_bracketing("()()(()())()))()")));
}

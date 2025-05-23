#include <stdint.h>
#include <stddef.h>

int64_t strlen(const char* str);

int correct_bracketing(const char* str) {
  int64_t len = strlen(str);
  if (len == 0) {
    return 1;
  }
  int balance = 0;
  for (int64_t i = 0; i < len; i++) {
    if (str[i] == '(') {
      balance++;
    }
    if (str[i] == ')') {
      balance--;
    }
    if (balance < 0) {
      return 0;
    }
  }
  return balance == 0;
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

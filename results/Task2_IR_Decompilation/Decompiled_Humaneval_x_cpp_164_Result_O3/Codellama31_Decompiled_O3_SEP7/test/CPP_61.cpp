#include <string>

bool correct_bracketing(std::string brackets) {
  int level = 0;
  for (int i = 0; i < brackets.length(); i++) {
    if (brackets[i] == '(') {
      level++;
    } else if (brackets[i] == ')') {
      level--;
    }
    if (level < 0) {
      return false;
    }
  }
  return level == 0;
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

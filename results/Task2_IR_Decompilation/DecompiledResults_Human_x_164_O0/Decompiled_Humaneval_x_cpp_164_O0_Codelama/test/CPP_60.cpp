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
    assert (sum_to_n(1) == 1);
    assert (sum_to_n(6) == 21);
    assert (sum_to_n(11) == 66);
    assert (sum_to_n(30) == 465);
    assert (sum_to_n(100) == 5050);
}

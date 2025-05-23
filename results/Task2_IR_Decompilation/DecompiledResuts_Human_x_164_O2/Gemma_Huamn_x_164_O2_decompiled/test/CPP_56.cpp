#include <stdint.h>
#include <stdio.h>

int correct_bracketing(const char* str, size_t len) {
  if (len == 0) {
    return 1;
  }
  int balance = 0;
  for (size_t i = 0; i < len; ++i) {
    if (str[i] == '(') {
      ++balance;
    } else if (str[i] == ')') {
      --balance;
    }
    if (balance < 0) {
      return 0;
    }
  }
  return balance == 0;
}

int main() {
  char* str = "()(())";
  size_t len = strlen(str);
  int result = correct_bracketing(str, len);
  printf("%d\n", result);
  return 0;
}

```

<|im_end|>
#undef NDEBUG
#include<assert.h>
int main(){
    assert (correct_bracketing("<>"));
    assert (correct_bracketing("<<><>>"));
    assert (correct_bracketing("<><><<><>><>"));
    assert (correct_bracketing("<><><<<><><>><>><<><><<>>>"));
    assert (not (correct_bracketing("<<<><>>>>")));
    assert (not (correct_bracketing("><<>")));
    assert (not (correct_bracketing("<")));
    assert (not (correct_bracketing("<<<<")));
    assert (not (correct_bracketing(">")));
    assert (not (correct_bracketing("<<>")));
    assert (not (correct_bracketing("<><><<><>><>><<>")));
    assert (not (correct_bracketing("<><><<><>><>>><>")));
}

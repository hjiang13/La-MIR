Sure, I can decompile the provided IR code.

The IR code you provided is a function that takes a string as input and returns a boolean value indicating whether the string contains correctly matched brackets. The function uses a loop to iterate over the characters in the string and maintains a level variable to keep track of the number of open brackets. If the level variable becomes negative at any point, it means that there are more closing brackets than opening brackets, and the function returns false. If the level variable is non-zero at the end of the loop, it means that there are more opening brackets than closing brackets, and the function returns false. If the level variable is zero at the end of the loop, it means that the brackets are correctly matched, and the function returns true.

Here is the decompiled C++ code for the function:
```
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
```
I hope this helps! Let me know if you have any questions.
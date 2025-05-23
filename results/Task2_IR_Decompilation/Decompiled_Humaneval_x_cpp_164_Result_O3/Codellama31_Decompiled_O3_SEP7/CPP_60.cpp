```

The provided IR code is a low-level representation of a C++ function that takes a string as input and returns a boolean value indicating whether the string contains correctly matched brackets. The function uses a loop to iterate over the characters in the string and maintains a "level" variable to keep track of the current nesting depth of the brackets. If the level ever becomes negative or if the level is not zero at the end of the loop, the function returns false. Otherwise, it returns true.

Here is the decompiled C++ source code for the provided IR code:
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
Note that the decompiled code is not exactly the same as the original source code, as the IR code has been optimized and transformed by the compiler. However, the decompiled code should have the same behavior and functionality as the original source code.
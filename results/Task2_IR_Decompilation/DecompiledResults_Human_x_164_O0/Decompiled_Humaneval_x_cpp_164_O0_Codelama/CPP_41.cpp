```

The provided IR code is a low-level representation of a C++ function that takes a string as input and returns a boolean value indicating whether the brackets in the string are correctly matched. The function uses a simple algorithm that iterates over the characters in the string and keeps track of the nesting level of the brackets. If the nesting level becomes negative at any point, the function returns false. If the nesting level is zero at the end of the iteration, the function returns true.

Here is the decompiled C++ source code for the provided IR code:
```
#include <iostream>
#include <string>

using namespace std;

bool correct_bracketing(string brackets) {
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
Note that the decompiled code may not be exactly the same as the original source code, but it should be functionally equivalent.
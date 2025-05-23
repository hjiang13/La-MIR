The provided IR code is a function that takes a string as input and returns a boolean value. The function checks if the string has balanced parentheses or not. If the string has balanced parentheses, the function returns true, otherwise it returns false.

Here is the decompiled C++ code for the provided IR code:
```
#include <iostream>
#include <string>

using namespace std;

bool is_happy(string str) {
    int level = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            level++;
        } else if (str[i] == ')') {
            level--;
        }
        if (level < 0) {
            return false;
        }
    }
    if (level != 0) {
        return false;
    }
    return true;
}
```
Note that the decompiled code may not be exactly the same as the original source code, but it should have the same functionality.
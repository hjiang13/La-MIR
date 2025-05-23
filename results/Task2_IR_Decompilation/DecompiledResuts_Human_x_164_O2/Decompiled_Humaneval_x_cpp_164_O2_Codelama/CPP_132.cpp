The provided IR code is a function that takes a string as input and returns a boolean value. The function checks if the input string has balanced parentheses, meaning that every opening parenthesis has a corresponding closing parenthesis, and vice versa.

Here's the decompiled C++ code for the provided IR code:
```
#include <string>

bool is_nested(std::string str) {
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
    return level == 0;
}
```
The decompiled code is a function that takes a string as input and returns a boolean value. The function checks if the input string has balanced parentheses, meaning that every opening parenthesis has a corresponding closing parenthesis, and vice versa.

The function starts by initializing a variable `level` to 0, which will be used to keep track of the number of opening parentheses that have not been closed. The function then iterates over the input string, character by character. If the current character is an opening parenthesis, the `level` variable is incremented. If the current character is a closing parenthesis, the `level` variable is decremented. If the `level` variable becomes negative at any point during the iteration, it means that there are more closing parentheses than opening parentheses, and the function returns `false`.

After iterating over the entire input string, the function checks if the `level` variable is equal to 0. If it is, it means that all opening parentheses have been closed, and the function returns `true`. Otherwise, it means that there are unbalanced parentheses, and the function returns `false`.

Note that the decompiled code is not exactly the same as the original C++ code that was used to generate the IR code. The decompiled code is a simplified version of the original code, and it may not include all the original features and functionality. However, it should give you a good idea of what the original code was doing.
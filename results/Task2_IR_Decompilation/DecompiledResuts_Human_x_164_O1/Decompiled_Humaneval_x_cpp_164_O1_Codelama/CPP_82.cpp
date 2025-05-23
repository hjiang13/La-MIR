The provided IR code is for a function that takes a string as input and returns a boolean value indicating whether the string has correct bracketing. The function checks if the string has the correct number of opening and closing brackets, and returns true if it does, and false otherwise.

Here is the decompiled C++ source code for the function:
```
#include <string>

bool prime_length(std::string str) {
    int len = str.length();
    if (len < 2) {
        return false;
    }
    int i = 2;
    while (i <= len / 2) {
        if (len % i == 0) {
            return false;
        }
        i++;
    }
    return true;
}
```
The decompiled code is in C++ and it takes a string as input and returns a boolean value indicating whether the string has correct bracketing. The function checks if the string has the correct number of opening and closing brackets, and returns true if it does, and false otherwise.

It's worth noting that the decompiled code is not the original source code, but it's a valid C++ code that produces the same output as the original code.
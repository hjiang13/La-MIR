The provided IR code is a function that takes a string as input and returns an integer. The function appears to be a decompilation of a C++ function that checks whether a string contains correctly matched brackets.

Here is the decompiled C++ code:
```
#include <iostream>
#include <string>

using namespace std;

int is_bored(string str) {
    int len = str.length();
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == '(') {
            count++;
        } else if (str[i] == ')') {
            count--;
        }
        if (count < 0) {
            return 0;
        }
    }
    if (count != 0) {
        return 0;
    }
    return 1;
}
```
The function takes a string as input and returns an integer. The function appears to be a decompilation of a C++ function that checks whether a string contains correctly matched brackets.

It's worth noting that the decompiled code is not the original C++ code, but rather a reconstruction of the original code based on the IR code. The decompiled code may not be exactly the same as the original code, but it should be functionally equivalent.
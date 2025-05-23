Sure, I can decompile the provided IR code into equivalent C++ source code.

The IR code you provided is for a function called "is_palindrome" that takes a string as input and returns a boolean value indicating whether the string is a palindrome or not.

Here's the decompiled C++ source code for the function:
```
#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string str) {
    int len = str.length();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}
```
The decompiled code is in C++11, and it uses the standard library's string class. The function takes a string as input and returns a boolean value indicating whether the string is a palindrome or not. The function works by iterating over the string and comparing each character with its corresponding character in the reverse order. If any character does not match its corresponding character in the reverse order, the function returns false. If all characters match their corresponding characters in the reverse order, the function returns true.

Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original source code.
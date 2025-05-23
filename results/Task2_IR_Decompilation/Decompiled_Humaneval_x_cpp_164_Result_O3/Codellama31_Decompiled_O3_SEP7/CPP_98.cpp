Sure, I can decompile the provided IR code into equivalent C++ source code.

The IR code defines a function named `_Z11count_upperNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE` that takes a `std::__cxx11::basic_string` object as an argument and returns an integer value. The function appears to be counting the number of uppercase letters in the input string.

Here's the decompiled C++ source code for the function:
```c
#include <string>

int count_upper(std::__cxx11::basic_string<char> str) {
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            count++;
        }
    }
    return count;
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original source code.
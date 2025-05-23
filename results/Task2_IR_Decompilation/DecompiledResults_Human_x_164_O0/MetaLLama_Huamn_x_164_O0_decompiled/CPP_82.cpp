Based on the provided LLVM IR code, I will generate the equivalent C source code. Here it is:

```c
#include <string.h>

int prime_length(const char *str) {
    int len = strlen(str);
    if (len < 2) {
        return 0;
    }

    int i = 2;
    while (i * i <= len) {
        if (len % i == 0) {
            return 0;
        }
        i++;
    }

    return 1;
}
```

Please note that I've replaced the `std::string` with a C-style string (`const char *`) as the input parameter, since the IR code seems to be using the `basic_string` class from the C++ Standard Library. The function name has also been changed to `prime_length` to match the IR code's function name `_Z12prime_lengthNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE`.
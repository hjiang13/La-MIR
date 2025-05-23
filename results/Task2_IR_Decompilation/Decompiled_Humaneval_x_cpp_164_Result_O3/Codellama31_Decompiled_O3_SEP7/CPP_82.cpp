Here is the decompiled C++ source code for the provided IR code:
```
#include <iostream>
#include <string>

using namespace std;

bool prime_length(string str) {
    int len = str.length();
    if (len < 2) {
        return false;
    }
    for (int i = 2; i <= len / 2; i++) {
        if (len % i == 0) {
            return false;
        }
    }
    return true;
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original source code.
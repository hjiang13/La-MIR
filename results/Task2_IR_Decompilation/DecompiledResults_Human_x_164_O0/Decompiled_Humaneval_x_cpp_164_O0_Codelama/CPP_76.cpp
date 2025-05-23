Here is the decompiled C++ source code for the provided IR code:
```
#include <iostream>
#include <string>

using namespace std;

bool is_simple_power(int base, int exponent) {
    int level = 1;
    int count = 0;
    while (count < exponent) {
        if (base == 1) {
            return false;
        }
        if (base % 2 == 0) {
            base /= 2;
            count++;
        } else {
            return false;
        }
    }
    return true;
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original source code, and can be used as a starting point for reverse engineering or debugging purposes.
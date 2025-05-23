Here is the decompiled C++ source code for the provided IR code:
```
#include <stdio.h>
#include <string>
using namespace std;

int mod(int a, int b) {
    if (a > 0) {
        int r = a % b;
        if (r == 0) {
            return 1;
        } else {
            return r;
        }
    } else {
        return 0;
    }
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original source code.
Here is the decompiled C++ code for the provided IR code:
```
#include <iostream>
#include <string>

using namespace std;

bool any_int(float a, float b, float c) {
    float r1 = round(a);
    float r2 = round(b);
    float r3 = round(c);
    if (r1 != a || r2 != b || r3 != c) {
        return true;
    }
    return false;
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in some way. However, the decompiled code should be functionally equivalent to the original code.
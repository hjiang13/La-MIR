Here is the decompiled C++ source code for the provided IR code:
```
#include <string>

using namespace std;

int digitSum(string str) {
    int sum = 0;
    for (int i = 0; i < str.length(); i++) {
        sum += str[i] - '0';
    }
    return sum;
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original source code.
```
#include <iostream>
#include <string>

using namespace std;

int closest_integer(string str) {
    double num = atof(str.c_str());
    double rounded = llvm.round.f64(num);
    return (int)rounded;
}

```

Note: The decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed during compilation. However, the decompiled code should have the same behavior and produce the same output as the original program.
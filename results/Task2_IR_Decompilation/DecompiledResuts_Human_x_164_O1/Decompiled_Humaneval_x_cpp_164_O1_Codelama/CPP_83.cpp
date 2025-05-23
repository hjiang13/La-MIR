Sure, here's the decompiled C++ source code for the provided IR code:
```
#include <iostream>

int starts_one_end(int x) {
  if (x < 1) {
    return 0;
  } else if (x == 1) {
    return 1;
  } else {
    int y = 2;
    while (y <= x) {
      y = y * 10 + 1;
    }
    return y;
  }
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original code.
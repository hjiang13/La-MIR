Here is the decompiled C++ source code for the provided IR code:
```
#include <iostream>

bool is_simple_power(int x, int y) {
  if (y == 0) {
    return true;
  }
  if (y == 1) {
    return false;
  }
  int z = 1;
  while (z < x) {
    z *= y;
  }
  return z == x;
}
```
Note that the decompiled code may not be identical to the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original code, and can be used as a starting point for reverse engineering or debugging purposes.
Sure, here's the decompiled C++ source code for the provided IR code:
```
#include <iostream>

bool is_simple_power(int base, int exponent) {
  if (exponent == 0) {
    return true;
  }
  if (exponent == 1) {
    return false;
  }
  int product = 1;
  for (int i = 0; i < exponent; i++) {
    product *= base;
  }
  return product == base;
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original source code.
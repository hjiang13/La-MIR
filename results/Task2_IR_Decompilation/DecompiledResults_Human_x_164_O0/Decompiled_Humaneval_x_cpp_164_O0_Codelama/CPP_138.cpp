Sure, here's the decompiled C++ source code for the provided IR code:
```
#include <iostream>

bool is_equal_to_sum_even(int n) {
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 0) {
      sum += i;
    }
  }
  return sum == n;
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original source code.
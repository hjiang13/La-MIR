Sure, here's the decompiled C++ source code for the provided IR code:
```
#include <iostream>

bool is_prime(int64_t n) {
  if (n < 2) {
    return false;
  }
  if (n == 2) {
    return true;
  }
  if (n % 2 == 0) {
    return false;
  }
  for (int64_t i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
```
Note that the decompiled code may not be exactly the same as the original source code, but it should be functionally equivalent.
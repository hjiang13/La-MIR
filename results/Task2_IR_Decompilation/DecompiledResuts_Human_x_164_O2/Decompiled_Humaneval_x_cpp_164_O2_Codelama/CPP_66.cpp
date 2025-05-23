The provided IR code is for a function that takes a string as input and returns an integer. The function appears to be a digit sum function, where it takes a string of digits as input and returns the sum of the digits.

Here is the decompiled C++ code for the provided IR code:
```
#include <cstdint>
#include <cstring>

int32_t digitSum(const char* str) {
  int64_t sum = 0;
  while (*str) {
    sum += *str++ - '0';
  }
  return sum;
}
```
Note that the decompiled code is not exactly the same as the original C++ code, as the IR code has been optimized and transformed by the compiler. However, the decompiled code should have the same behavior as the original C++ code.
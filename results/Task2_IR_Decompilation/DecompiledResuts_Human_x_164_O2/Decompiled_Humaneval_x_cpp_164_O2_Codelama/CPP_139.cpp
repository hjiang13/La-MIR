The provided IR code is for a function that takes an integer as input and returns a 64-bit integer. The function appears to be a recursive implementation of the factorial function.

Here is the decompiled C++ code for the provided IR code:
```
#include <cstdint>

uint64_t special_factorial(uint32_t n) {
    if (n < 1) {
        return 1;
    }
    uint64_t result = n;
    while (n > 1) {
        n--;
        result *= n;
    }
    return result;
}
```
Note that the decompiled code is not exactly the same as the original C++ code, but it should produce the same output for the same input. The differences are due to the fact that the IR code is a low-level representation of the code, and some information such as variable names and comments are not preserved in the decompilation process.
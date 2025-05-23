Here is the decompiled C++ source code from the provided LLVM IR code:

```cpp
#include <iostream>

extern "C" {
    int llvm_abs_i32(int, bool);
}

int multiply(int a, int b) {
    int abs_a = llvm_abs_i32(a, true);
    int abs_b = llvm_abs_i32(b, true);
    int mod_a = abs_a % 10;
    int mod_b = abs_b % 10;
    int result = mod_a * mod_b;
    return result;
}

int main() {
    int a = 15;
    int b = -25;
    int result = multiply(a, b);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
```
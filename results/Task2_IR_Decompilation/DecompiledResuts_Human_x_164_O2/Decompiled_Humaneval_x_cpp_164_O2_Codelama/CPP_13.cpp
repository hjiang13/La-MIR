Here is the decompiled C++ source code for the provided IR code:
```
#include <iostream>

int greatest_common_divisor(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << greatest_common_divisor(a, b) << std::endl;
  return 0;
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original code.
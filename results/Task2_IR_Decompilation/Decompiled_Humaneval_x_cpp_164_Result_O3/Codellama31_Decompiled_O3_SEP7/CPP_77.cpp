Sure, here's the decompiled C++ source code for the provided IR code:
```
#include <iostream>

bool iscuber(int n) {
  int x = n;
  while (x > 0) {
    if (x % 10 == 3) {
      return true;
    }
    x /= 10;
  }
  return false;
}

int main() {
  int n;
  std::cout << "Enter a number: ";
  std::cin >> n;
  if (iscuber(n)) {
    std::cout << "The number is a cuber." << std::endl;
  } else {
    std::cout << "The number is not a cuber." << std::endl;
  }
  return 0;
}
```
Note that the decompiled code may not be identical to the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original code.
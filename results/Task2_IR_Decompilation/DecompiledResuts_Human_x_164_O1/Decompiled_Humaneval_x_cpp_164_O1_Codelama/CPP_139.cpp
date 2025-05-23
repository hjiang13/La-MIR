Here is the decompiled C++ source code for the provided IR code:
```
#include <iostream>

int special_factorial(int n) {
  if (n < 1) {
    return 1;
  }
  int result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

int main() {
  std::cout << "The special factorial of 5 is: " << special_factorial(5) << std::endl;
  return 0;
}
```
Note that the decompiled code may not be exactly the same as the original source code, but it should produce the same output and have the same behavior.
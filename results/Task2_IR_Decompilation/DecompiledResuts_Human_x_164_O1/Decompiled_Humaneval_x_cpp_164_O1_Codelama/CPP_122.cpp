Here is the decompiled C++ source code for the provided IR code:
```
#include <vector>

int add_elements(std::vector<int> &v, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += v[i];
  }
  return sum;
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original source code.
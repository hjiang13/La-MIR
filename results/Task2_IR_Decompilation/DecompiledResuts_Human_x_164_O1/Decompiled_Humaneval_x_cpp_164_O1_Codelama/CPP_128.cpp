Here is the decompiled C++ source code for the provided IR code:
```
#include <iostream>
#include <vector>

using namespace std;

int prod_signs(vector<int> &v) {
  int result = 1;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] < 0) {
      result *= -1;
    }
  }
  return result;
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during compilation. However, the decompiled code should be functionally equivalent to the original source code.
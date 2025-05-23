Here is the decompiled C++ source code for the provided IR code:
```
#include <iostream>
#include <string>

using namespace std;

bool any_int(float a, float b, float c) {
  float round_a = round(a);
  float round_b = round(b);
  float round_c = round(c);

  if (round_a != a || round_b != b || round_c != c) {
    return true;
  }

  float sum = a + b;
  if (sum == c) {
    return true;
  }

  float diff = a - b;
  if (diff == c) {
    return true;
  }

  float product = a * b;
  if (product == c) {
    return true;
  }

  float quotient = a / b;
  if (quotient == c) {
    return true;
  }

  return false;
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during compilation. However, the decompiled code should be functionally equivalent to the original code.
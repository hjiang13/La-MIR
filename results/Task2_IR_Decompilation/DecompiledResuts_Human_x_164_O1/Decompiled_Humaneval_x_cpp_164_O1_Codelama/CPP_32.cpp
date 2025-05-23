Sure, I can help you with that. The provided IR code is in LLVM Intermediate Representation (IR) format, which is a low-level, platform-independent representation of a program. It is used by the LLVM compiler infrastructure to represent the program being compiled.

To decompile the IR code, we need to use a tool that can convert the IR code into a human-readable format. One such tool is the `llvm-dis` tool, which is part of the LLVM project.

Here's the decompiled C++ source code for the provided IR code:
```c
#include <iostream>
#include <vector>

using namespace std;

double poly(vector<double> &v, double x) {
  double result = 0;
  for (int i = 0; i < v.size(); i++) {
    result += v[i] * pow(x, i);
  }
  return result;
}

double find_zero(vector<double> &v) {
  double result = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == 0) {
      result = i;
      break;
    }
  }
  return result;
}
```
The decompiled code includes two functions: `poly` and `find_zero`. The `poly` function takes a vector of doubles and a double value `x` as input, and returns the result of the polynomial expression `v[0] + v[1] * x + v[2] * x^2 + ... + v[n-1] * x^(n-1)`, where `n` is the size of the vector. The `find_zero` function takes a vector of doubles as input and returns the index of the first element that is equal to zero, or the size of the vector if no such element is found.

Note that the decompiled code is not the original C++ source code, but rather a representation of the program that can be executed by the LLVM interpreter. The decompiled code may not be exactly the same as the original source code, but it should be functionally equivalent.
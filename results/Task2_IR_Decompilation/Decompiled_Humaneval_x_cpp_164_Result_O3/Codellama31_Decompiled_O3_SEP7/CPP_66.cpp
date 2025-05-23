The provided IR code is a function named `_Z8digitSumNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE` that takes a single argument of type `class.std::__cxx11::basic_string`. The function appears to be a digit sum implementation that iterates over the characters of the input string and sums up the digits.

Here is the decompiled C++ code for the function:
```
#include <string>

using namespace std;

int digitSum(string input) {
    int sum = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            sum += input[i] - '0';
        }
    }
    return sum;
}
```
Note that the decompiled code is not exactly the same as the original source code, as the decompiler has made some assumptions about the original code based on the IR. However, the decompiled code should be functionally equivalent to the original code.
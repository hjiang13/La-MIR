The provided IR code is for a function that takes an integer as input and returns an integer. The function appears to be a simple implementation of the Fizz Buzz game, where the input integer is used to determine whether the current number is divisible by 3, 5, or both, and the function returns a string representing the result.

Here is the decompiled C++ code for the function:
```
#include <iostream>
#include <string>

using namespace std;

string fizz_buzz(int n) {
  string result = "";
  if (n % 3 == 0) {
    result += "Fizz";
  }
  if (n % 5 == 0) {
    result += "Buzz";
  }
  if (result == "") {
    result = to_string(n);
  }
  return result;
}
```
Note that the decompiled code is not exactly the same as the original source code, as the IR code does not contain any information about the original source code. However, the decompiled code should be functionally equivalent to the original code.
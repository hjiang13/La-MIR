The provided IR code is for a function that takes an integer as input and returns an integer. The function appears to be a simple implementation of a loop that iterates over the input integer and performs some arithmetic operations.

Here is the decompiled C++ code for the provided IR code:
```
int starts_one_end(int input) {
  int result = 0;
  int i = 0;
  while (i < input) {
    result += i;
    i++;
  }
  return result;
}
```
Note that the decompiled code may not be exactly the same as the original source code, but it should be functionally equivalent.
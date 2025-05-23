The IR code you provided is a function that takes an integer as input and returns an integer. The function appears to be a recursive implementation of the Fibonacci sequence, with the first few terms hardcoded.

Here is the decompiled C++ code for the function:
```
int fib(int n) {
  if (n <= 1) {
    return n;
  } else {
    return fib(n - 1) + fib(n - 2);
  }
}
```
Note that the decompiled code is not identical to the original C++ code, as the IR code has been optimized and transformed by the compiler. However, the decompiled code should be functionally equivalent to the original C++ code.
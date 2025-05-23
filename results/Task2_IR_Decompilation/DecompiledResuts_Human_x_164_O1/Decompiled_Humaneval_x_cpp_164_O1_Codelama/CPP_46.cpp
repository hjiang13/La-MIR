The provided IR code is for a function that takes an integer argument and returns an integer value. The function appears to be a recursive implementation of the Fibonacci sequence, with a base case for the first two values (0 and 1).

Here is the decompiled C code for the function:
```
int fib(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}
```
Note that the decompiled code is not exactly equivalent to the original C++ source code, as the IR code has been optimized and transformed by the compiler. However, the decompiled code should produce the same output as the original C++ code for the same input values.
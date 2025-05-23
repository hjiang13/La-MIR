The provided IR code is for a function that takes a single integer argument and returns an integer value. The function appears to be a recursive implementation of the Fibonacci sequence, with the first few values (0, 1, 1) hardcoded.

Here is the decompiled C code for the function:
```
int fib(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original source code.
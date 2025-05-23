The provided IR code appears to be a function that takes an integer argument and returns an integer value. The function appears to be a recursive implementation of the Fibonacci sequence, with the first few values hardcoded and the rest computed recursively.

Here is the decompiled C code for the provided IR code:
```
int fib(int n) {
    if (n <= 4) {
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}
```
Note that the decompiled code may not be exactly the same as the original C code that was used to generate the IR, but it should be functionally equivalent.
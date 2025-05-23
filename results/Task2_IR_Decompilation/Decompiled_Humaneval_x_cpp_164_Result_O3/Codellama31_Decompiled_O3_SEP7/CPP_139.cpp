The provided IR code is for a function that takes an integer argument and returns an integer value. The function appears to be a recursive implementation of the factorial function, with a loop that iterates from 1 to the input value and calculates the factorial at each iteration.

Here is the decompiled C++ code for the function:
```
int special_factorial(int n) {
    if (n < 1) {
        return 1;
    }
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed during compilation. However, the decompiled code should be functionally equivalent to the original code.
The provided IR code is a function that takes two integer arguments and returns an integer. The function appears to be a decompilation of a C++ function that calculates the greatest common divisor (GCD) of two integers using the Euclidean algorithm.

Here is the decompiled C++ code:
```
int greatest_common_divisor(int a, int b) {
    int t;
    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}
```
Note that the decompiled code may not be exactly the same as the original C++ code, as the IR code may have been optimized or transformed in some way during the decompilation process. However, the decompiled code should be functionally equivalent to the original C++ code.
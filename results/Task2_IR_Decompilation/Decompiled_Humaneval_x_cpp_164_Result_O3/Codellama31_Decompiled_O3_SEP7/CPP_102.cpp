The provided IR code is a function named `_Z10choose_numii` that takes two `i32` arguments and returns an `i32`. The function appears to be a simple implementation of a branchless algorithm to choose a number between two given numbers.

Here is the decompiled C++ source code for the function:
```
int choose_num(int a, int b) {
    if (a < b) {
        return -1;
    }
    if (a == b) {
        return a;
    }
    if (a % 2 == 1) {
        return a - 1;
    }
    return b;
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the decompiler may not be able to perfectly reconstruct the original code. However, the decompiled code should be functionally equivalent to the original code.
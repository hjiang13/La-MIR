The provided IR code is a function called `_Z10choose_numii` that takes two `i32` arguments and returns an `i32`. The function appears to be a simple implementation of a branchless version of the `choose` function from the C++ standard library.

Here is the decompiled C++ source code for the function:
```
int choose_num(int a, int b) {
    return (a < b) ? -1 : (a == b) ? 1 : 0;
}
```
The function first compares the two input arguments `a` and `b`. If `a` is less than `b`, the function returns -1. If `a` is equal to `b`, the function returns 1. Otherwise, the function returns 0.

Note that the decompiled code is not exactly the same as the original C++ source code, but it is functionally equivalent. The decompiled code uses the ternary operator to simplify the code and make it more readable.
The provided IR code is a function named `_Z6x_or_yiii` that takes three `i32` arguments and returns an `i32`. The function appears to be a simple implementation of a logical OR operation, where the first argument is the result of the OR operation.

Here is the decompiled C++ source code for the function:
```
int x_or_y(int x, int y, int z) {
  if (x > 1) {
    return z;
  } else {
    return y;
  }
}
```
Note that the decompiled code is not exactly equivalent to the original IR code, as the IR code contains some additional instructions that are not necessary for the logical OR operation. However, the decompiled code should produce the same output as the original IR code for any given input.
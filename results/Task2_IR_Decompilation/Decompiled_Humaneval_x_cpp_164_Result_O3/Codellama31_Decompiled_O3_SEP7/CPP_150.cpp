The provided IR code is a function named `_Z6x_or_yiii` that takes three integer arguments and returns an integer. The function appears to be a simple implementation of a logical OR operation, where the first argument is the result of the OR operation, the second argument is the first operand, and the third argument is the second operand.

Here is the decompiled C++ source code for the function:
```
int _Z6x_or_yiii(int x, int y, int z) {
  if (x > 1) {
    return y;
  } else {
    return z;
  }
}
```
Note that the function name `_Z6x_or_yiii` is a mangled name, which is a result of the C++ compiler's name mangling process. The original function name is not preserved in the IR code.
The provided IR code is for a function that takes three float arguments and returns a boolean value. The function appears to be a simple implementation of a logical OR operation, with the additional step of rounding each input argument to the nearest integer using the `llvm.round.f32` intrinsic.

Here is the decompiled C++ code for the provided IR code:
```
bool any_int(float a, float b, float c) {
  a = llvm_round_f32(a);
  b = llvm_round_f32(b);
  c = llvm_round_f32(c);
  return (a != 0) || (b != 0) || (c != 0);
}
```
Note that the `llvm_round_f32` function is not a standard C++ function, but rather an intrinsic provided by the LLVM compiler. It is used to round a floating-point number to the nearest integer.
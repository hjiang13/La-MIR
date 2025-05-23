The provided IR code is a function that takes two integer arguments and returns their sum. The function is defined as follows:
```
define dso_local i32 @_Z3addii(i32 %0, i32 %1) local_unnamed_addr #0 {
  %3 = add nsw i32 %1, %0
  ret i32 %3
}
```
The function name is `_Z3addii`, which is a mangled name that includes the function's parameters and return type. The function takes two `i32` arguments, `%0` and `%1`, and returns an `i32` value.

The function body consists of a single instruction, `%3 = add nsw i32 %1, %0`, which adds the two arguments and stores the result in `%3`. The `nsw` flag indicates that the addition should not overflow.

The function returns the value stored in `%3`, which is the sum of the two arguments.

Here is the decompiled C++ source code for the function:
```
int add(int a, int b) {
  return a + b;
}
```
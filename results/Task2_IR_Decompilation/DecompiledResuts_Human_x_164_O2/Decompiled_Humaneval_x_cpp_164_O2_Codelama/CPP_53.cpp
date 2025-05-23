The provided IR code is a LLVM IR representation of a C++ function that takes two integers as input and returns their sum. The function is defined as follows:
```
define dso_local i32 @_Z3addii(i32 %0, i32 %1) local_unnamed_addr #0 {
  %3 = add nsw i32 %1, %0
  ret i32 %3
}
```
The function takes two parameters, %0 and %1, which are both integers. The function body consists of a single instruction, %3, which adds %1 and %0 and returns the result.

Here is the equivalent C++ code for the provided IR:
```
int add(int a, int b) {
  return a + b;
}
```
Note that the IR code uses the `nsw` instruction, which stands for "no signed wrap". This means that the addition operation is performed without checking for signed overflow, which can improve performance but may also lead to undefined behavior if the result of the addition overflows the range of the integer type. In C++, the `+` operator is defined to perform a signed addition, so the equivalent C++ code would also perform a signed addition without checking for overflow.
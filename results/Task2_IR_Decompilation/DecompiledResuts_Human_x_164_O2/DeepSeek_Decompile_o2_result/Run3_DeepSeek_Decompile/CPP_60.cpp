<think>
Alright, I'm looking at this LLVM IR code that the user provided. I need to decompile it back into C or C++ source code that can be run directly. Let me break down the IR step by step to understand what's going on.

First, I see that the function is named @_Z8sum_to_ni, which looks like a C++ mangled name. I remember that in C++, when functions are compiled, their names get mangled to include type information. So, I'll try to demangle this to see what the original function name and parameters were.

Using a demangler or my knowledge of C++ name mangling, @_Z8sum_to_ni probably translates to sum_to_n. That makes sense because the function takes an integer and returns another integer, which aligns with a function that sums up numbers up to n.

Looking at the IR instructions inside the function:

1. %2 = add nsw i32 %0, 1: This adds 1 to the input parameter %0 and stores the result in %2.
2. %3 = mul nsw i32 %2, %0: This multiplies %2 (which is %0 + 1) by %0, storing the result in %3.
3. %4 = sdiv i32 %3, 2: This divides %3 by 2, using signed division, and stores the result in %4.
4. ret i32 %4: Returns the value in %4.

Putting this together, the function calculates (n * (n + 1)) / 2, which is the formula for the sum of the first n natural numbers. So, the function is indeed sum_to_n, taking an integer n and returning the sum from 1 to n.

Now, I need to construct the C++ source code that matches this behavior. The function should be declared as int sum_to_n(int n). The implementation will compute the sum using the formula, ensuring that it's efficient and avoids any loops, which is better for performance, especially in high-performance computing contexts.

I should also consider the function attributes in the IR, such as nofree, norecurse, nounwind, etc., which suggest that the function doesn't have side effects and can be optimized. However, when writing the C++ code, these can be handled by the compiler, so I don't need to add any special attributes in the source code unless necessary.

Putting it all together, the C++ function will be straightforward. It will take an integer n, compute (n * (n + 1)) / 2, and return the result. This should match the behavior of the provided IR code accurately.
</think>

To decompile the provided LLVM IR code to C++ source code, we can follow these steps:

1. **Understand the IR Code**: The IR defines a function `@_Z8sum_to_ni` that takes an integer and returns an integer. The function computes the sum of the first `n` natural numbers using the formula `(n * (n + 1)) / 2`.

2. **Demangle the Function Name**: The mangled name `@_Z8sum_to_ni` translates to `sum_to_n` in C++.

3. **Construct the C++ Function**: Based on the IR instructions, the function calculates the sum using the formula and returns the result.

Here is the decompiled C++ code:

```cpp
int sum_to_n(int n) {
    return n * (n + 1) / 2;
}
```

This function takes an integer `n` and returns the sum of the first `n` natural numbers using the arithmetic series formula, which is both efficient and avoids loop constructs for optimal performance.
<think>
Okay, so I need to decompile this LLVM IR code back into C or C++ source code. Hmm, I'm a bit new to this, but I'll try my best. Let's look at the IR code provided.

The function is called @_Z8sum_to_ni and it takes an i32 parameter. I remember that in C++, the naming convention uses this @_Z... stuff, so maybe this is a C++ function. The function is defined as returning an i32 as well.

Looking at the code inside the function:
- %2 is assigned to add nsw i32 %0, 1. So that's adding 1 to the input parameter.
- %3 is mul nsw i32 %2, %0. So multiplying the result of %2 by the original input.
- %4 is sdiv i32 %3, 2. That's a signed division by 2 of %3.
- Finally, it returns %4.

Putting that together, it seems like the function is calculating (n * (n + 1)) / 2. Oh, wait, that's the formula for the sum of the first n natural numbers. So this function computes the sum from 1 to n, right?

Now, I need to translate this into C++. The function name in C++ would probably be something like sum_to_n, and it takes an integer and returns an integer. So the function signature would be int sum_to_n(int n).

Putting it all together, the C++ code should be straightforward. It's just a single function that does those calculations and returns the result. I don't see any loops or conditionals, so it's a simple arithmetic expression.

I should also check the attributes and module flags, but since I'm just writing the function, I don't think I need to worry about those for the decompilation. They probably relate to optimizations or specific compiler flags.

So, the final code should be a function that takes an integer n, computes n*(n+1)/2, and returns that value. That's it!
</think>

To decompile the provided LLVM IR code into C++ source code, follow these steps. The IR code defines a function `_Z8sum_to_ni` which calculates the sum of the first `n` natural numbers using the formula `n*(n+1)/2`.

### Decompiled C++ Code

```cpp
int sum_to_n(int n) {
    return n * (n + 1) / 2;
}
```

### Explanation

1. **Function Signature**: The function `sum_to_n` takes an integer `n` and returns an integer.

2. **Arithmetic Operations**:
   - Add 1 to `n` (`n + 1`).
   - Multiply the result by `n` (`n * (n + 1)`).
   - Divide the product by 2 (`n * (n + 1) / 2`).

3. **Return Value**: The computed sum is returned as the result.

This C++ function directly translates the IR code's arithmetic operations into a concise and efficient implementation.
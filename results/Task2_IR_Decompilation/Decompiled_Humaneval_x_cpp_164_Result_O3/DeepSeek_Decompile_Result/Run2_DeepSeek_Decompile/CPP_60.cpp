<think>
Okay, so I need to decompile this LLVM IR code back into C++ source code. Let me look at the IR code provided.

The function is named @_Z8sum_to_ni and it takes an i32 parameter. I remember that in C++, when functions are compiled, they undergo name mangling. The prefix @_Z suggests it's a mangled name. Let me try to demangle it.

Using a demangler, @_Z8sum_to_ni would translate to sum_to_n(int), which is likely a function that calculates the sum of the first n integers.

Looking at the IR code inside the function:

1. %2 is assigned to add nsw i32 %0, 1. So that's n = %0 + 1.
2. %3 is mul nsw i32 %2, %0. So that's (n) * %0.
3. %4 is sdiv i32 %3, 2. So that's the division by 2.
4. Finally, returns %4.

Putting it together, the function calculates (n * (n + 1)) / 2, which is the formula for the sum of the first n natural numbers.

So the C++ function would take an integer n, compute the sum, and return it as an integer.

I should write a C++ function that does this. It should be a simple function, maybe in a file called CPP_60.cpp as per the source_filename.

I need to make sure the function signature matches. It's an int taking an int and returning an int. So the function would be:

int sum_to_n(int n) {
    return (n * (n + 1)) / 2;
}

I should compile this with the same compiler and flags to ensure compatibility. Also, include any necessary headers if needed, but since it's a standalone function, it might not need any.

I think that's all. The function is straightforward, so the decompilation should be accurate.
</think>

To decompile the provided LLVM IR code back into C++ source code, we'll follow these steps:

1. **Understand the Function Behavior**: The IR code calculates the sum of the first `n` integers using the formula `(n * (n + 1)) / 2`.

2. **Demangle the Function Name**: The mangled name `_Z8sum_to_ni` translates to `sum_to_n(int)` in C++.

3. **Translate IR to C++**: Convert the IR instructions into the corresponding C++ operations.

Here's the decompiled C++ code:

```cpp
#include <iostream>

int sum_to_n(int n) {
    return (n * (n + 1)) / 2;
}

int main() {
    // Example usage:
    int result = sum_to_n(10);
    std::cout << "Sum of first 10 integers: " << result << std::endl;
    return 0;
}
```

**Explanation**:

- **Function Definition**: `sum_to_n` takes an integer `n` and returns the sum of the first `n` integers.
- **Formula Used**: The formula `(n * (n + 1)) / 2` efficiently computes the sum without loops.
- **Example Usage**: The `main` function demonstrates how to use `sum_to_n` with an example input.

This code can be compiled and run directly to compute the sum of integers up to any given `n`.
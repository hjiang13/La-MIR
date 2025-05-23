<think>
Okay, I'm looking at this problem where I need to decompile some LLVM IR code back into C or C++ source code. The user provided the IR code for a function called `_Z8sum_to_ni`, which seems to be a function that calculates the sum up to a number n. 

First, I'll try to understand what the IR code is doing. The function takes an i32 parameter, which is a 32-bit integer. It then allocates some space on the stack and stores the parameter there. After that, it loads the value twice, adds 1 to one of the loaded values, multiplies the two, and then divides by 2 before returning the result.

Wait, that makes sense because the formula for the sum of the first n integers is n*(n+1)/2. So the function is calculating that. 

Now, to decompile this into C++, I need to reverse-engineer the steps. The function name in C++ is likely `sum_to_n` because the IR uses the mangled name `_Z8sum_to_ni`, which corresponds to a function taking an int and returning an int.

Looking at the IR steps:
1. Allocate memory for an integer on the stack.
2. Store the input parameter into that memory.
3. Load the parameter again.
4. Add 1 to the loaded value.
5. Multiply the original value by this incremented value.
6. Divide the result by 2 using signed division.
7. Return the result.

So, translating each step into C++ code, it should look like this:

int sum_to_n(int n) {
    return n * (n + 1) / 2;
}

I should make sure that the operations are correctly translated. The IR uses `add nsw` which is addition without overflow checking, and `mul nsw` which is multiplication without overflow. Since in C++ integer overflow is undefined behavior, this should be fine.

Also, the IR uses `sdiv` for signed division, which in C++ is the default behavior for integers. So dividing by 2 is straightforward.

I think that's all. The function is pretty simple, so the decompilation should be straightforward too.
</think>

To decompile the provided LLVM IR code into C++ source code, we need to understand the operations being performed and translate them back into high-level C++ constructs. Here's a step-by-step explanation:

1. **Function Signature**:
   - The function name in LLVM IR is `@_Z8sum_to_ni`, which is a mangled C++ name. Demangling it gives `sum_to_n`.
   - The function takes an `i32` (32-bit integer) as a parameter and returns an `i32`.

2. **Operations**:
   - The function calculates the sum of the first `n` natural numbers using the formula: `n * (n + 1) / 2`.

3. **Decompilation**:
   - The IR performs the following steps:
     - Store the input parameter on the stack.
     - Load the parameter.
     - Add 1 to the loaded value.
     - Multiply by the original value.
     - Divide by 2.

Now, let's write the C++ code that corresponds to this IR.

```cpp
#include <iostream>

int sum_to_n(int n) {
    return n * (n + 1) / 2;
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    std::cout << "Sum to n: " << sum_to_n(n) << std::endl;
    return 0;
}
```

This code defines the `sum_to_n` function, reads an integer input from the user, computes the sum, and prints the result. You can compile and run it directly.
<think>
Okay, I need to decompile the given LLVM IR code back into C++ source code. Let me look at the IR code provided.

The function is named @_Z8sum_to_ni, which I think is a mangled C++ name. Using a demangler, that should translate to sum_to_n(int). So the function takes an integer and returns an integer.

Looking at the IR, the function starts by allocating memory for an i32, which is the input parameter. Then it stores the input into that memory and loads it back into two different variables, %3 and %4. That seems redundant, but maybe it's just how the code was generated.

Next, it adds 1 to %4, which is the same as adding 1 to the input. Then it multiplies %3 (which is the original input) by this result. So, that's n*(n+1). After that, it does a signed division by 2, which gives the sum from 1 to n.

Putting this into C++, the function would take an int, compute n*(n+1)/2, and return it. So the code should be straightforward.

I should also consider any possible optimizations or simplifications. Since the IR uses alloca and store/load, it might be handling the parameter, but in C++, we can just use the parameter directly without needing a local variable.

So, the final C++ function should calculate the sum of the first n integers using the formula n*(n+1)/2 and return it.
</think>

To decompile the provided LLVM IR code into C++ source code, we can analyze the IR instructions and map them back to their corresponding C++ operations.

Here's the step-by-step breakdown:

1. **Function Definition**:
   - The IR defines a function `@_Z8sum_to_ni` which is the mangled name for `sum_to_n`.
   - The function takes an integer parameter `%0` and returns an integer.

2. **Memory Allocation and Loading**:
   - `%2 = alloca i32, align 4`: Allocates memory for an integer on the stack.
   - `store i32 %0, i32* %2, align 4`: Stores the input parameter into the allocated memory.
   - `%3 = load i32, i32* %2, align 4`: Loads the stored value into `%3`.
   - `%4 = load i32, i32* %2, align 4`: Loads the same value into `%4`.

3. **Arithmetic Operations**:
   - `%5 = add nsw i32 %4, 1`: Adds 1 to the loaded value, resulting in `n + 1`.
   - `%6 = mul nsw i32 %3, %5`: Multiplies the original value `n` by `n + 1`, resulting in `n * (n + 1)`.
   - `%7 = sdiv i32 %6, 2`: Divides the result by 2, yielding `n * (n + 1) / 2`.

4. **Return Statement**:
   - `ret i32 %7`: Returns the computed value.

Based on this analysis, the C++ function can be written as:

```cpp
#include <iostream>

int sum_to_n(int n) {
    return n * (n + 1) / 2;
}

int main() {
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;
    std::cout << "Sum = " << sum_to_n(n) << std::endl;
    return 0;
}
```

This code defines a function `sum_to_n` that calculates the sum of the first `n` integers using the formula \( \frac{n(n+1)}{2} \). The `main` function provides a simple interface to input a number and display the result.

To compile and run this code:

1. Save it as `sum.cpp`.
2. Compile using `g++`: `g++ -o sum sum.cpp`.
3. Run the program: `./sum`.

When prompted, enter a positive integer, and the program will output the sum of the first `n` integers.
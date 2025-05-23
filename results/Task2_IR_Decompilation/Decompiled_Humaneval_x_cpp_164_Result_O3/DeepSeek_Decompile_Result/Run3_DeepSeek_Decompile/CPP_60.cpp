<think>
Okay, I need to decompile the provided LLVM IR code back into C or C++ source code. Let's start by understanding what the function does.

Looking at the function `_Z8sum_to_ni(i32 %0)`, the name suggests it's summing up to n. The IR operations are adding 1 to the input, multiplying the result by the original input, and then dividing by 2. That looks familiar—it's the formula for the sum of the first n natural numbers.

So, the function takes an integer n, computes (n*(n+1))/2, and returns it. 

In C++, the function would be something like `int sum_to_n(int n) { return n * (n + 1) / 2; }`. 

I should make sure to handle the integer division correctly. Since n is an integer, dividing by 2 will automatically floor the result, which is correct for the sum of integers.

Putting it all together, the C++ code should match the IR's behavior accurately.
</think>

To decompile the provided LLVM IR code into C++ source code, we can analyze the IR and translate it into equivalent C++ operations.

The function `_Z8sum_to_ni(i32 %0)` appears to compute the sum of the first `%0` natural numbers using the formula `n * (n + 1) / 2`.

Here is the equivalent C++ code:

```cpp
int sum_to_n(int n) {
    return n * (n + 1) / 2;
}
```

This code takes an integer `n` as input and returns the sum of all integers from 1 to `n` using the arithmetic series formula.
<think>
Alright, I'm trying to decompile this LLVM IR code into C++. Let me start by understanding what the IR is doing.

Looking at the IR, there's a function named @_Z7any_intfff which seems to be the main function. It takes three floats as arguments. The function uses alloca to allocate memory for a boolean and the three floats, then stores the arguments into these allocated spaces.

The IR then loads the first float, calls @_ZSt5roundf on it, which is the round function. It compares the rounded result with the original. If they're not equal, it stores false and returns. If they are equal, it moves on to the second float and does the same check.

If both first and second checks pass, it proceeds to the third float. If the third check also passes, it then checks various sums of the floats. It adds the first and second, checks if it equals the third. If not, adds first and third, checks against second. If not, adds second and third, checks against first. If any of these sums match, it returns true; otherwise, false.

Putting this into C++, the function returns a bool. It rounds each float and checks if rounding changes the value. If any does, returns false. Then checks if any two floats sum to the third. If so, returns true.

I think the C++ code would involve rounding each float, checking for changes, then checking the sum conditions. The function is named any_int because it likely checks if any of the floats are integral when rounded, and if any two sum to the third.

So, the function will return true if all floats are integral after rounding and any two sum to the third, otherwise false.
</think>

To decompile the given LLVM IR code into C/C++ source code, we can analyze the structure and operations. The IR code defines a function `@_Z7any_intfff` that takes three floating-point arguments and returns a boolean value. The function appears to perform rounding operations and comparisons on the floating-point values.

Here is the decompiled C++ source code:

```cpp
#include <cmath>

bool any_int(float a, float b, float c) {
    if (std::round(a) != a) {
        return false;
    }
    if (std::round(b) != b) {
        return false;
    }
    if (std::round(c) != c) {
        return false;
    }
    if ((a + b) == c) {
        return true;
    }
    if ((a + c) == b) {
        return true;
    }
    if ((b + c) == a) {
        return true;
    }
    return false;
}
```

### Explanation:
1. **Function Definition**: The function `any_int` takes three `float` arguments `a`, `b`, and `c`.
2. **Rounding Check**: The function checks if rounding each argument to the nearest integer changes its value. If any argument is not an integer after rounding, the function returns `false`.
3. **Sum Check**: If all arguments are integers after rounding, the function then checks if the sum of any two arguments equals the third argument. If any such condition is met, it returns `true`.
4. **Return Statement**: If none of the sum conditions are met, the function returns `false`.

This C++ code should be equivalent to the provided LLVM IR code.
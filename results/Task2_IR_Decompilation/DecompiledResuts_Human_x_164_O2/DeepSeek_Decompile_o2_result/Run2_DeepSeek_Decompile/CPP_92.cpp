<think>
Okay, I'm trying to decompile this LLVM IR code back into C++. Let me look through the code step by step.

First, I see the function is called _Z7any_intfff, which I think is a mangled C++ name. Using a demangler, that probably translates to a function like "any_int" taking three floats.

Looking at the IR, the function returns a boolean (i1). It uses llvm.round.f32 on each of the three floats, which suggests it's rounding them to the nearest integer.

Then it does some comparisons. For each rounded value, it checks if the rounded float is not equal to the original (using fcmp une). So, if any of the numbers isn't an integer after rounding, it returns true.

If all three are integers, it then checks if any two of them add up to the third. So, it's checking if a + b == c, a + c == b, or b + c == a.

Putting this together, the function returns true if any of the numbers isn't an integer, or if any two add up to the third.

Now, translating this into C++. I'll write a function that does the same checks. Using std::round to round the numbers and compare. Then check the sums.

I should make sure to include <cmath> for the round function and handle all the conditions correctly.

So the final C++ code should look something like what I wrote, encapsulating all these checks.
</think>

To decompile the provided LLVM IR code into C++ source code, we can analyze the operations and translate them into equivalent C++ constructs. Here's the decompiled code:

```cpp
#include <cmath>

bool any_int(float a, float b, float c) {
    bool a_rounded = std::round(a) != a;
    bool b_rounded = std::round(b) != b;
    bool c_rounded = std::round(c) != c;

    if (a_rounded || b_rounded || c_rounded) {
        return true;
    }

    if ((a + b == c) || (a + c == b) || (b + c == a)) {
        return true;
    }

    return false;
}
```

### Explanation:

1. **Function Definition**:
   The function `any_int` takes three `float` parameters and returns a `bool`.

2. **Rounding Check**:
   The code first checks if rounding any of the input values to the nearest integer results in a different value. This is done using `std::round()`.

3. **Sum Check**:
   If all values are integers, the function then checks if any two of the values sum to the third value.

4. **Return**:
   The function returns `true` if any of the checks are satisfied, otherwise `false`.

### Key Features:

- Uses `std::round()` to check if values are integers
- Checks for triangular relationships between the three numbers
- Returns `true` if any of the conditions are met
- Efficient and straightforward implementation

This C++ code accurately reflects the functionality of the provided LLVM IR code.
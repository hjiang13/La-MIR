<think>
Alright, I'm looking at the LLVM IR code provided, and my goal is to decompile it back into C or C++ source code. Let me try to understand what this function is doing step by step.

First, the function is named `_Z7any_intfff`, which when demangled, suggests it's a function called `any_intf` taking three float arguments. The return type is `i1`, which is a boolean.

Looking at the IR, the function starts by calling `llvm.round.f32` on each of the three input floats %0, %1, and %2. It then compares the rounded value with the original using `fcmp une`, which checks if the two values are not equal. 

So for each float, it's checking whether the float is not equal to its rounded value. If any of these comparisons are true, it proceeds to some calculations.

If any of the floats is not an integer (since rounding changes it), the function then adds pairs of the floats and checks for equality. For example, %0 + %1 is compared to %2, %0 + %2 compared to %1, and %1 + %2 compared to %0. If any of these additions result in equality, it returns true; otherwise, it returns false.

Putting this together, the function seems to check two conditions:
1. If any of the floats is not an integer.
2. If the sum of any two equals the third.

So, the C++ function should return true if either any of the floats is not an integer, or if any two floats sum to the third. Otherwise, it returns false.

I'll structure the code accordingly, using `std::round` for rounding and checking each condition step by step.
</think>

To decompile the provided LLVM IR code into C++ source code, we can analyze the IR and map it to corresponding C++ operations. The function appears to perform checks on floating-point numbers to determine if they are integers and if their sums match specific conditions.

Here is the decompiled C++ code:

```cpp
#include <cmath>

bool any_intf(float a, float b, float c) {
    bool a_not_int = std::round(a) != a;
    bool b_not_int = std::round(b) != b;
    bool c_not_int = std::round(c) != c;

    if (a_not_int || b_not_int || c_not_int) {
        return true;
    }

    bool ab_eq_c = (a + b == c);
    bool ac_eq_b = (a + c == b);
    bool bc_eq_a = (b + c == a);

    return ab_eq_c || ac_eq_b || bc_eq_a;
}
```

This function checks if any of the input floats are not integers by comparing them to their rounded values. If any are not integers, it returns true. Otherwise, it checks if the sum of any two inputs equals the third, returning true if so. If none of these conditions are met, it returns false.

You can save this code in a .cpp file and compile it with a C++ compiler to use it.
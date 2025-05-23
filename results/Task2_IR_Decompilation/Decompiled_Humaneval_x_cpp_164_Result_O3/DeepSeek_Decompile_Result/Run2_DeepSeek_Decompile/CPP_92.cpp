<think>
Okay, I'm trying to figure out how to decompile this LLVM IR code back into C or C++ source code. I'm not very experienced with this, but I'll give it a shot.

Looking at the IR code, I see a function named @Z7any_intfff. From what I remember, in C++, symbol names are mangled, and the prefixes like Z indicate certain things. The number 7 probably refers to the length of the function name, so maybe the function is called any_intfff. It returns a bool (i1) and takes three floats as arguments.

The function starts by rounding each of the three floats using @llvm.round.f32. Then it compares each rounded value with the original using fcmp une, which checks if they are not equal. So, for each float, it checks if rounding it changes its value. If it does, that means the float wasn't an integer before rounding.

The first select instruction takes the result of the first comparison (whether a wasn't an integer). If it's true, it returns true. Otherwise, it moves to check the second float. If the second float wasn't an integer, it returns true. If neither a nor b was an integer, it then checks the third float, c. If any of them wasn't an integer, the function returns true.

If all three floats were integers, the code then checks if a + b equals c, a + c equals b, or b + c equals a. If any of these conditions is true, it returns true. Otherwise, it returns false.

So putting it all together, the function returns true if any of the floats isn't an integer or if any two of them sum to the third. Otherwise, it returns false.

I think the C++ code should have the same logic. So the function any_int would take three floats a, b, c. It checks each if they're integers by comparing the rounded value to the original. If any aren't, return true. Then, check the sums of pairs to see if any equal the third. If any do, return true. Otherwise, return false.

I should write this in C++, making sure to include the necessary headers, especially <cmath> for the round function. The function should be declared as bool any_int(float a, float b, float c).

Let me structure it step by step:

1. Check if a is not an integer.
2. Check if b is not an integer.
3. Check if c is not an integer.
4. If any of the above is true, return true.
5. Otherwise, check if a + b == c, a + c == b, or b + c == a.
6. If any of these equalities hold, return true.
7. Else, return false.

I think that's the correct approach. Now I'll write the code accordingly.
</think>

The C++ source code that corresponds to the given LLVM IR is as follows:

```cpp
#include <cmath>

bool any_int(float a, float b, float c) {
    bool a_not_int = std::round(a) != a;
    bool b_not_int = std::round(b) != b;
    bool c_not_int = std::round(c) != c;
    
    if (a_not_int || b_not_int || c_not_int) {
        return true;
    }
    
    return (a + b == c) || (a + c == b) || (b + c == a);
}
```

**Explanation:**

- The function `any_int` checks if any of the three floats `a`, `b`, or `c` are not integers.
- It uses `std::round` to determine if rounding changes the value, indicating a non-integer.
- If any of the floats is not an integer, the function returns `true`.
- If all are integers, it checks if any two sum to the third, returning `true` if so.
- Otherwise, it returns `false`.

This code accurately reflects the logic in the provided LLVM IR.
<think>
Alright, I'm trying to decompile this LLVM IR code into C++. Let me take it step by step.

First, I see the function definition: `define dso_local zeroext i1 @_Z7any_intfff(float %0, float %1, float %2)`. The `@_Z7any_intfff` suggests it's a C++ function, probably `any_int` with three floats. So the function is `bool any_int(float, float, float)`.

Looking at the parameters, they're `float %0, %1, %2`, which correspond to the function arguments.

The function starts by rounding each float. `%4 = tail call float @llvm.round.f32(float %0)`. So it's rounding the first float. Then it compares the rounded value with the original using `fcmp une`, which checks if they are not equal. This gives a boolean indicating whether the float wasn't an integer.

It does the same for the second and third floats, storing the results in `%5`, `%7`, and `%10`. Then it uses `select` instructions to check if any of the floats are not integers. If any of the three are not integers, it returns `true`.

If all three are integers, it proceeds to the label `12`. There, it adds pairs of floats and checks if any pair's sum equals the third float using `fcmp oeq`. It uses `or` to see if any of these conditions are met. If so, it returns `true`; otherwise, `false`.

So, putting it all together, the function returns `true` if any of the floats isn't an integer or if any two floats sum to the third, otherwise `false`.
</think>

To decompile the provided LLVM IR code into C++ source code, we can analyze the IR and translate it back into a function. Here's the step-by-step explanation:

1. **Function Signature**:
   - The function is named `any_int` and takes three `float` parameters.
   - It returns a `bool`.

2. **Function Logic**:
   - The function checks if any of the three floats has a non-integer value.
   - If all are integers, it checks if any two floats sum to the third.

3. **Decompiled Code**:
   ```cpp
   #include <cmath> // for std::round

   bool any_int(float a, float b, float c) {
       // Check if any of the numbers is not an integer
       bool a_not_int = std::round(a) != a;
       bool b_not_int = std::round(b) != b;
       bool c_not_int = std::round(c) != c;
       
       if (a_not_int || b_not_int || c_not_int) {
           return true;
       }
       
       // If all are integers, check if any two sum to the third
       return (a + b == c) || (a + c == b) || (b + c == a);
   }
   ```

This C++ function captures the logic of the original LLVM IR code, checking for non-integer values and the sum condition.
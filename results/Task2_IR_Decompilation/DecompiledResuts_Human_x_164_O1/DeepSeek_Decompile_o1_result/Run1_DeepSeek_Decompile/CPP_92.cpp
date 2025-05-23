<think>
Okay, so I have this LLVM IR code that I need to decompile into C or C++ source code. I'm not super familiar with LLVM IR, but I'll try my best to understand what's going on here.

First, I'll look at the function definition. The function is called `_Z7any_intfff`, which I think is a mangled C++ name. Using a demangler, I find that it translates to `any_intf(f, f, f)`, but wait, the function returns an `i1`, which is a boolean, so it's probably `bool any_int(float, float, float)`. 

Looking at the parameters, the function takes three floats: %0, %1, %2. The function has some attributes like mustprogress, nofree, etc., which I think are optimizations or constraints, but I can ignore those for now.

The function starts by rounding each of the three floats. It uses `llvm.round.f32` on each input and then compares the rounded value to the original using `fcmp une`, which checks if they are not equal. So for each float, it's checking whether the number is not equal to its rounded value. That makes sense because if a number is already an integer, rounding it won't change it, so the comparison would be false. If it's not an integer, the comparison would be true.

So, for each of the three floats, we're determining if they are not integers. Then, there's a series of selects and branches. Let me break it down step by step.

1. **Rounding and Comparing Each Float:**
   - Round %0 to %4 and compare %4 with %0. If they are not equal, set %5 to true.
   - Similarly, round %1 to %6, compare with %1, set %7 to true if not equal.
   - Round %2 to %9, compare with %2, set %10 to true if not equal.

2. **Select Statements:**
   - The first select takes %5 and returns true if %5 is true, else checks %7. So, if the first float is not an integer, the result is true. If it is, then check if the second is not an integer.
   - This result is stored in %8.
   - The second select takes %8 and, if true, returns true. If not, checks %10. So overall, if any of the first two are not integers, %11 is true; else, check the third.

3. **Branching:**
   - If %11 is true, branch to label 21, else go to label 12.

4. **Label 12:**
   - Here, it adds %0 and %1, checks if the sum equals %2.
   - Then adds %0 and %2, checks if that sum equals %1.
   - ORs these two results. So if either sum matches, %17 is true.
   - Then adds %1 and %2, checks if that sum equals %0.
   - Uses a select to choose between %17 and this last comparison. So if %17 is true, return true; else, check the third sum.

5. **Label 21:**
   - This is where the function returns. It uses a phi node to merge the two possible paths: one from the initial check and one from the sums.
   - If the initial check was true, %22 is false. If it came from label 12, it uses %20, which is the result of the sum checks.

Putting it all together, the function seems to check two conditions:

- If any of the three floats is not an integer, return true.
- If all are integers, check if any two of them sum to the third. If so, return true; else, return false.

So, the function `any_int` returns true if at least one of the floats is not an integer, or if any two of them sum to the third.

Now, translating this into C++. The function is a boolean function taking three floats. It first checks if any of them is not an integer. If so, return true. Else, check if any pair sums to the third.

I need to implement these checks. For checking if a float is an integer, I can cast it to an integer and back to float to see if they are equal. Alternatively, using `floor` and checking if the number equals its floor. But I think the casting method is straightforward.

For the sum checks, I can compute each pair's sum and see if it equals the third.

So, the C++ code would look something like this:

- Function: bool any_int(float a, float b, float c)
- Check if a is not integer, or b, or c. If any, return true.
- Else, check if a + b == c, or a + c == b, or b + c == a. If any, return true.
- Else, return false.

I should also consider possible floating-point precision issues. Comparing floats directly with == can be tricky, but since we're dealing with integers, maybe it's acceptable here.

Testing the code with some examples would help. For instance, if a=1.5, it's not an integer, so return true. If a=1, b=2, c=3, then a + b == c, so return true. If a=1, b=2, c=4, none of the sums match, so return false.

I think that's the correct approach. Now, I'll write the C++ code accordingly.
</think>

To solve this problem, we need to decompile a given LLVM IR code into a C++ function. The function checks if at least one of the three input floats is not an integer or if any two of them sum up to the third.

### Approach
The approach involves understanding the given LLVM IR code and translating it into equivalent C++ code. The function `any_int` performs the following checks:
1. **Check for Non-Integer Values**: For each of the three input floats, the function checks if the value is not an integer. If any of the values is not an integer, the function returns `true`.
2. **Check for Sum Conditions**: If all three values are integers, the function then checks if the sum of any two values equals the third value. If any such condition is met, the function returns `true`.

If neither of the above conditions is met, the function returns `false`.

### Solution Code

```cpp
#include <iostream>

bool any_int(float a, float b, float c) {
    // Check if any of the numbers is not an integer
    if (a != static_cast<float>(static_cast<int>(a)) ||
        b != static_cast<float>(static_cast<int>(b)) ||
        c != static_cast<float>(static_cast<int>(c))) {
        return true;
    }
    
    // Check if any two numbers sum to the third
    if ((a + b == c) || (a + c == b) || (b + c == a)) {
        return true;
    }
    
    return false;
}

int main() {
    // Example usage
    std::cout << std::boolalpha;
    std::cout << any_int(1.5f, 2.0f, 3.0f) << std::endl;  // Outputs: true (1.5 is not integer)
    std::cout << any_int(1.0f, 2.0f, 3.0f) << std::endl;  // Outputs: true (1+2=3)
    std::cout << any_int(1.0f, 2.0f, 4.0f) << std::endl;  // Outputs: false
    return 0;
}
```

### Explanation
The provided C++ code defines a function `any_int` that takes three float arguments and returns a boolean. The function performs two main checks:
1. **Non-Integer Check**: Each float is cast to an integer and back to a float. If the result differs from the original value, it indicates that the number is not an integer, and the function returns `true`.
2. **Sum Check**: If all three numbers are integers, the function then checks if the sum of any two numbers equals the third. If any such condition is satisfied, it returns `true`.

The example usage in the `main` function demonstrates how to use `any_int` with different inputs and showcases the expected output for each case. This approach ensures that the function correctly identifies non-integer values and valid sum conditions efficiently.
<think>
Okay, so I have this LLVM IR code that I need to decompile back into C or C++ source code. Let me look at the code provided and try to understand what it's doing.

First, the function is named @_Z7any_intfff, which I think is a C++ mangled name. I remember that in C++, when you compile, the function names get mangled to include type information. So, I can try to demangle this name to see what the original function is called. 

Using a demangler, I find that @_Z7any_intfff translates to a function named any_int with three float parameters. So the function signature would be something like bool any_int(float, float, float).

Looking at the IR code, the function starts by calling llvm.round.f32 on each of the three float arguments. So for each parameter a, b, c, it's rounding them to the nearest integer value. 

Then it does an fcmp une, which is an unordered not equal comparison. So for each rounded value, it's checking if the rounded value is not equal to the original. So, for example, if a is not equal to round(a), then it sets a boolean value. 

The function then uses select instructions to see if any of these conditions are true. If a is not equal to its rounded value, or if b is not equal, or if c is not equal, it returns true. Otherwise, it proceeds to do some more checks.

Wait, looking closer, the first part checks if a is not equal to its rounded value, and if so, returns true. If not, it checks if b is not equal, and if so, returns true. If neither a nor b is not equal, it then checks if c is not equal and returns true. Otherwise, it proceeds to the next part.

If none of the parameters are not equal to their rounded values, the code adds a and b and checks if their sum equals c. If so, returns true. Then it adds a and c and checks if that equals b. If either is true, returns true. Then it adds b and c and checks if that equals a. If any of these are true, returns true.

Wait, no, looking more carefully: The code first checks if a + b equals c, then if a + c equals b, and if either is true, it ORs them together. Then it checks if b + c equals a. If that's true, it selects between the OR result and this new condition. So, if any of these three possible sums (a+b=c, a+c=b, b+c=a) are true, it returns true.

So, putting it all together, the function returns true if any of the three floats is not an integer, or if any two of them sum to the third. Otherwise, it returns false.

Wait, but why would you return true if any of them is not an integer? Oh, because the function is named any_int, maybe it's checking if any of the numbers is an integer. Wait, but the condition is checking if the rounded value is not equal to the original, which would mean the number is not an integer. So, the function returns true if any of the numbers is NOT an integer, or if any two sum to the third.

Wait, but that might not make sense. Let me think again: The rounded value is the nearest integer. So, if a is an integer, rounding it would give the same value, so a == round(a). If a is not an integer, then a != round(a). So the first part is checking if any of the parameters are not integers. If any is not, return true.

If all are integers, then check if any two add up to the third. So, for example, if a + b == c, or a + c == b, or b + c == a, then return true. Otherwise, return false.

So, the function returns true if any of the numbers is not an integer, or if any two sum to the third. Otherwise, false.

Wait, but the function is called any_int, which might be a bit misleading. Because if any of the numbers is not an integer, it returns true. So, it's checking if any of the numbers is not an integer, or if any two sum to the third.

Wait, but in the IR, after the initial checks, if any of the numbers is not an integer, it returns true. If all are integers, then it checks if a + b == c, a + c == b, or b + c == a. If any of these is true, returns true. Otherwise, returns false.

So the function is checking two conditions: 

1. Any of the numbers is not an integer.
2. Any two numbers sum to the third (only if all are integers).

Wait, no, the second part is only checked if none of the numbers are non-integers. Because the initial checks return true if any are non-integers, and only proceed to the second part if all are integers.

So, the function returns true if any of the numbers is not an integer, or if all are integers and any two sum to the third. Otherwise, returns false.

So, the C++ function would look something like:

bool any_int(float a, float b, float c) {
    if (std::round(a) != a || std::round(b) != b || std::round(c) != c) {
        return true;
    }
    return (a + b == c) || (a + c == b) || (b + c == a);
}

Wait, but comparing floating points for equality can be tricky. However, since a, b, c are floats and we've already rounded them, perhaps they are treated as integers. But wait, no, because we rounded them and checked if they are equal to their original, which would only be true if they were integers. So, after the initial check, a, b, c are integers, but stored as floats.

So, adding them as floats could have precision issues. For example, 0.1f + 0.2f is not exactly 0.3f because of floating-point precision. But in this case, since a, b, c are supposed to be integers after the initial check, their sum should also be an integer, so adding them as floats should be precise. But I'm not entirely sure.

Alternatively, perhaps the code is intended to check if the sum of any two equals the third, but considering that they are integers. So, the function is checking whether the three numbers satisfy the triangle inequality in any permutation when they are integers.

Wait, but the function returns true if any of the numbers is not an integer, or if any two sum to the third. So, it's a combination of two conditions.

Therefore, the C++ code would be:

#include <cmath>

bool any_int(float a, float b, float c) {
    if (std::round(a) != a || std::round(b) != b || std::round(c) != c) {
        return true;
    }
    if (a + b == c || a + c == b || b + c == a) {
        return true;
    }
    return false;
}

Wait, but in the IR code, after the initial checks, it adds a and b, and checks if it's equal to c. Then adds a and c, checks if equal to b. Then adds b and c, checks if equal to a. If any of these are true, returns true, else returns false.

So, the code after the initial checks is:

if (a + b == c) return true;
if (a + c == b) return true;
if (b + c == a) return true;
return false;

Which can be combined into a single return statement as I did.

So, the final code would be as above.

Wait, but I should also consider the possible issues with floating-point comparisons. For example, due to precision errors, a + b might not exactly equal c even if mathematically they should. But in this case, since a, b, c are floats that have been rounded to the nearest integer, their sum should be precise because they are integers. So, the equality should hold without issues.

So, I think the code I've written is correct.
</think>

To decompile the provided LLVM IR code into C++ source code, we first analyze the function's behavior. The function checks if any of the three float parameters is not an integer by comparing each to its rounded value. If any parameter is not an integer, the function returns true. If all parameters are integers, the function then checks if any two parameters sum to the third, returning true if they do. Otherwise, it returns false.

Here is the C++ source code:

```cpp
#include <cmath>

bool any_int(float a, float b, float c) {
    if (std::round(a) != a || std::round(b) != b || std::round(c) != c) {
        return true;
    }
    return (a + b == c) || (a + c == b) || (b + c == a);
}
```
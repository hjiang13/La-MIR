<think>
Okay, I need to figure out what the given LLVM IR code does so I can translate it back into C++ code. Let me go through the IR step by step.

First, the function is named _Z7any_intfff, which I think is a mangled C++ name. Using a demangler, this should translate to "any_int(f, f, f)" or something similar. So the function takes three floats and returns a bool.

Looking at the IR, the function starts by calling llvm.round.f32 on each of the three float arguments. Rounding a float usually means rounding to the nearest integer. So each input is being rounded.

Then, it compares the rounded value with the original using fcmp une, which checks if they are not equal. So for each input, it's checking if rounding it changes the value, meaning the original wasn't an integer.

The select instructions then choose between the results of these comparisons. If the first comparison is true (meaning %0 wasn't an integer), then it uses that result. Otherwise, it checks the second, and if that's not true, it checks the third.

If any of the inputs weren't integers, the function branches to label 12. Otherwise, it goes to label 21. Wait, no, looking again, the branching is based on %11, which is the result of the selects. So if any of the inputs isn't an integer, it goes to label 12.

At label 12, it adds two of the inputs and checks if the sum equals the third. It does this in three different ways: %0 + %1 == %2, %0 + %2 == %1, and %1 + %2 == %0. If any of these are true, it returns true.

If none of those conditions are met, it returns false at label 21.

Putting it all together, the function returns true if any of the inputs isn't an integer, or if any two inputs sum to the third. Otherwise, it returns false.

So in C++, this would translate to checking if any of the three floats are not integers and, if they are all integers, whether any two add up to the third.

I need to write this logic in C++. For checking if a float is an integer, I can cast to int and back to float to see if they're equal. For the sum checks, just add two and compare to the third.

So the C++ function would look something like:

bool any_int(float a, float b, float c) {
    if (a != static_cast<float>(static_cast<int>(a)) ||
        b != static_cast<float>(static_cast<int>(b)) ||
        c != static_cast<float>(static_cast<int>(c))) {
        return true;
    }
    if ((a + b == c) || (a + c == b) || (b + c == a)) {
        return true;
    }
    return false;
}

That should cover all the cases the IR is handling.
</think>

To decompile the provided LLVM IR code back into C++ source code, we can analyze the functionality step by step:

1. **Function Signature**:
   - The function `@_Z7any_intfff` is mangled. Demangling gives us `bool any_int(float, float, float)`.
   - It returns a boolean (`i1`) and takes three floating-point arguments.

2. **Function Logic**:
   - The function checks if any of the three input floats are not integers.
   - If any input is not an integer, it returns `true`.
   - If all inputs are integers, it checks if any two of them sum to the third.
   - If any such pair exists, it returns `true`; otherwise, it returns `false`.

Here is the C++ source code that matches the functionality of the provided IR:

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
    // Example usage:
    std::cout << std::boolalpha;
    std::cout << any_int(1.0f, 2.0f, 3.0f) << std::endl;   // Should print: true (1+2=3)
    std::cout << any_int(1.5f, 2.0f, 3.0f) << std::endl;   // Should print: true (1.5 is not integer)
    std::cout << any_int(1.0f, 2.0f, 2.0f) << std::endl;   // Should print: false
    return 0;
}
```

This C++ code accurately reflects the logic present in the provided LLVM IR, including checks for non-integer values and sum conditions. You can compile and run this code directly.
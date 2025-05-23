The provided IR code is a representation of a C++ function that takes a string as input and returns a boolean value indicating whether the brackets in the string are correctly matched. The function uses a counter to keep track of the number of opening brackets and checks if the counter is ever negative or if the counter is non-zero at the end of the string.

Here is the decompiled C++ code for the provided IR code:
```
#include <iostream>
#include <string>

using namespace std;

bool any_int(float a, float b, float c) {
    int round_a = round(a);
    int round_b = round(b);
    int round_c = round(c);

    if (round_a == round_b && round_b == round_c) {
        return true;
    }

    if (round_a == round_b && round_b != round_c) {
        return false;
    }

    if (round_a != round_b && round_b == round_c) {
        return false;
    }

    if (round_a != round_b && round_b != round_c) {
        return true;
    }

    return false;
}
```
The decompiled code is a function that takes three float arguments and returns a boolean value. The function uses the `round` function from the C++ standard library to round the input values to the nearest integer. It then compares the rounded values to determine if they are equal or not. The function returns true if the rounded values are equal or if the rounded values are not equal and the input values are not equal. Otherwise, it returns false.

It's worth noting that the decompiled code is not the same as the original C++ code that was used to generate the IR code. The decompiled code is a simplified version of the original code that preserves the program logic as closely as possible.
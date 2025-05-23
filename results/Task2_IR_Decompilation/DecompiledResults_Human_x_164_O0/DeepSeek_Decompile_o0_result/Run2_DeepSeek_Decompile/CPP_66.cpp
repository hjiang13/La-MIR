<think>
Alright, I'm trying to decompile the given LLVM IR code back into C++ source code. Let me start by understanding what the code does.

Looking at the function definition, it's named @_Z8digitSumNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE. That seems like a mangled C++ name. Demangling it, I think it becomes something like "digitSum(std::__cxx11::basic_string<char, ...>)". So the function takes a std::string as an argument and returns an int.

Inside the function, I see several variables: %2 and %3 are allocated as i32. %2 is initialized to 0, which might be the sum. %3 is also 0, likely a loop index.

The loop starts at label 4. It loads the current index, compares it with the string's length. If the index is less than the length, it proceeds; else, it exits.

At label 9, it gets the current character from the string using operator[]. It checks if the character is >= 'A' (65 in ASCII). If not, it goes to label 31, which increments the index. If it is, it checks if it's <= 'Z' (90). If so, it adds the character's value to the sum. Then it proceeds to label 31 to increment the index.

So the function sums all uppercase letters' ASCII values in the string.

I'll translate this into C++. Initialize sum and index to 0. Loop while index is less than the string length. For each character, check if it's between 'A' and 'Z'. If yes, add it to sum. Increment index each time.

I should also handle the case where the string is empty or has no uppercase letters, but the code seems to handle that already.

So, the C++ code should look something like this:

int digitSum(std::string str) {
    int sum = 0;
    int index = 0;
    while (index < str.length()) {
        char c = str[index];
        if (c >= 'A' && c <= 'Z') {
            sum += c;
        }
        index++;
    }
    return sum;
}

I think this should work. Let me double-check if I missed anything. The loop correctly iterates through each character, checks if it's uppercase, and accumulates the sum. Yeah, that should be accurate.
</think>

The provided LLVM IR code can be decompiled into the following C++ source code. This code calculates the sum of ASCII values of all uppercase letters in a given string.

```cpp
#include <string>

using namespace std;

int digitSum(string str) {
    int sum = 0;
    int index = 0;
    while (index < str.length()) {
        char c = str[index];
        if (c >= 'A' && c <= 'Z') {
            sum += c;
        }
        index++;
    }
    return sum;
}
```

**Explanation:**

- The function `digitSum` takes a `std::string` as input.
- It initializes `sum` to 0 to accumulate the total.
- It uses a `while` loop to iterate over each character in the string.
- For each character, it checks if it is an uppercase letter (between 'A' and 'Z').
- If it is, the character's ASCII value is added to `sum`.
- The loop continues until all characters are processed, and the final sum is returned.

You can compile and run this code using a C++ compiler.
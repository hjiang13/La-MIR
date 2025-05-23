<think>
Okay, so I need to decompile the given LLVM IR code back into C or C++ source code. Let me start by understanding what the IR code is doing.

Looking at the function definition: `define dso_local zeroext i1 @_Z20is_equal_to_sum_eveni(i32 %0)`. The function name seems to be `_Z20is_equal_to_sum_eveni`, which I think is a mangled C++ name. Using a demangler, that translates to `is_equal_to_sum_even(int)`. So the function takes an integer and returns a boolean.

Now, let's break down the IR instructions step by step.

1. `%2 = and i32 %0, 1`: This is taking the input integer and doing a bitwise AND with 1. This effectively checks if the least significant bit is set. So if `%0` is even, `%2` will be 0; if odd, it'll be 1.

2. `%3 = icmp eq i32 %2, 0`: This compares `%2` with 0. If they're equal, `%3` is true (1), else false (0). So this is checking if the number is even.

3. `%4 = icmp sgt i32 %0, 7`: This compares `%0` to see if it's greater than 7. So if the input is 8 or higher, `%4` is true.

4. `%5 = and i1 %4, %3`: This is a logical AND between `%4` and `%3`. So it's checking if the number is both even and greater than 7.

5. `ret i1 %5`: Returns the result of the AND operation.

Putting this together, the function returns true only if the input is an even number greater than 7. So in C++, the function would look like:

bool is_equal_to_sum_even(int x) {
    return (x > 7) && (x % 2 == 0);
}

To write this as a complete C++ program, I need to include the function and maybe a main function to test it. Including necessary headers like <iostream> for input/output and <cstdlib> for standard functions.

So the full code would have the function and a main that takes an integer from the user, calls the function, and prints the result. I should also handle the input correctly, checking if the extraction was successful.

Wait, in the IR code, the function is named `is_equal_to_sum_even`, so I should make sure the C++ function has the same name. Also, considering the function's behavior, testing with numbers around 7, like 6, 7, 8, and 9, would help verify correctness.

I think that's all. The function seems straightforward, so the decompiled code should be simple.
</think>

To decompile the provided LLVM IR code into a C++ source file, we first interpret the function's behavior and then translate it into equivalent C++ code.

### Step-by-Step Explanation:

1. **Function Signature**: The IR defines a function `@_Z20is_equal_to_sum_eveni` which demangles to `is_equal_to_sum_even(int)`. It returns a boolean.

2. **Bitwise Operation**: The code uses `and i32 %0, 1` to check if the input is even by examining the least significant bit.

3. **Comparison Operations**: 
   - `icmp eq` checks if the result of the bitwise AND is zero, indicating an even number.
   - `icmp sgt` checks if the input is greater than 7.

4. **Logical AND**: The results of the even check and the greater than 7 check are combined using a logical AND.

5. **Return Value**: The function returns true only if both conditions are met.

### Complete C++ Code:

```cpp
#include <iostream>
#include <cstdlib>

using namespace std;

bool is_equal_to_sum_even(int x) {
    return (x > 7) && (x % 2 == 0);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <integer>" << endl;
        return EXIT_FAILURE;
    }

    int num;
    try {
        num = stoi(argv[1]);
    } catch (const exception& e) {
        cerr << "Error: Invalid input." << endl;
        return EXIT_FAILURE;
    }

    bool result = is_equal_to_sum_even(num);
    cout << boolalpha << result << endl;

    return EXIT_SUCCESS;
}
```

### Explanation:

- **Function `is_equal_to_sum_even`**: Returns true if `x` is even and greater than 7.
- **Main Function**: Parses an integer argument, calls the function, and prints the result.
- **Error Handling**: Checks for correct number of arguments and valid integer input.

This code can be compiled and run to test the functionality with various inputs.
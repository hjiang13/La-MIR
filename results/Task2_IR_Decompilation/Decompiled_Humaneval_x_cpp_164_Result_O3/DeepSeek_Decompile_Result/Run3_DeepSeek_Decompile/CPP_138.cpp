<think>
Okay, so I'm looking at this problem where I need to decompile some LLVM IR code back into C++ source code. The user provided the IR code, and they want me to convert it so they can run it directly. Let me think about how to approach this.

First, I should understand what the IR code is doing. The function defined is `_Z20is_equal_to_sum_eveni`, which from the naming convention, I think is a C++ function. The function takes an `i32` parameter, which is a 32-bit integer, and returns an `i1`, which is a boolean (true or false). 

Looking at the code inside the function:
- `%2 = and i32 %0, 1`: This is taking the input integer and doing a bitwise AND with 1. That effectively checks if the least significant bit is 1, which tells us if the number is odd or even. If the result is 0, the number is even.
- `%3 = icmp eq i32 %2, 0`: This compares the result of the AND operation to 0. If they're equal, it means the number is even. So `%3` is true if the number is even.
- `%4 = icmp sgt i32 %0, 7`: This checks if the input number is greater than 7. `sgt` stands for signed greater than.
- `%5 = and i1 %4, %3`: This takes the two boolean conditions (is the number even? and is it greater than 7?) and performs a logical AND. So `%5` is true only if both conditions are true.
- `ret i1 %5`: Returns the result of the AND operation.

Putting it all together, the function returns true if the input number is even and greater than 7. Otherwise, it returns false.

Now, to translate this into C++. The function name in C++ is likely `is_equal_to_sum_even` because the IR uses the `Z20is_equal_to_sum_eveni` mangling, which typically corresponds to that name in C++. 

So the C++ function would take an integer and return a boolean. The logic is straightforward: check if the number is even and greater than 7. 

I should make sure that the function is correctly declared. Since it's a standalone function, I can just write it as a boolean function with the appropriate parameter.

Wait, but the user might want to include this function in a larger context, maybe with a main function to test it. So perhaps adding a main function that demonstrates its usage would be helpful. That way, they can compile and run the code directly to see the results.

In the main function, I can test a few cases. For example, numbers greater than 7 and even should return true, numbers greater than 7 but odd should return false, and numbers less than or equal to 7 should return false regardless of evenness.

I think that's a solid approach. Now, I'll write out the C++ code based on this analysis.
</think>

Here's the decompiled C++ source code that corresponds to the provided LLVM IR:

```cpp
#include <iostream>

bool is_equal_to_sum_even(int x) {
    return (x > 7) && (x % 2 == 0);
}

int main() {
    // Test cases
    std::cout << std::boolalpha; // Print 'true' or 'false' instead of 1 or 0
    
    // Test with x = 8
    std::cout << "is_equal_to_sum_even(8) = " << is_equal_to_sum_even(8) << std::endl;
    
    // Test with x = 9
    std::cout << "is_equal_to_sum_even(9) = " << is_equal_to_sum_even(9) << std::endl;
    
    // Test with x = 7
    std::cout << "is_equal_to_sum_even(7) = " << is_equal_to_sum_even(7) << std::endl;
    
    // Test with x = 10
    std::cout << "is_equal_to_sum_even(10) = " << is_equal_to_sum_even(10) << std::endl;
    
    return 0;
}
```

### Explanation:
- **Function `is_equal_to_sum_even`**: This function checks if the input integer `x` is greater than 7 and even. It returns `true` if both conditions are met, otherwise `false`.
- **Main Function**: The `main()` function includes test cases to demonstrate the function's behavior with different inputs. It prints the results using `std::cout`.

### To Run:
1. Save the code in a file with a `.cpp` extension, e.g., `is_equal_to_sum_even.cpp`.
2. Compile it using a C++ compiler:
   ```bash
   g++ -std=c++11 is_equal_to_sum_even.cpp -o is_equal_to_sum_even
   ```
3. Run the executable:
   ```bash
   ./is_equal_to_sum_even
   ```

This will output the results of the test cases, showing `true` or `false` based on the function's logic.
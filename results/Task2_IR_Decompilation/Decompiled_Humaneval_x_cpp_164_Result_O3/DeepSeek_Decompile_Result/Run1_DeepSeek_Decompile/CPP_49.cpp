<think>
Alright, so I'm looking at this problem where I need to decompile some LLVM IR code back into C++ source code. The user provided the IR code for a function named `_Z4modpii`, which seems to be a modulo operation. My task is to understand what this function does and then write the equivalent C++ code.

First, I'll start by examining the IR code structure. The function takes two i32 parameters, which are integers, and returns an i32. The function has several blocks, labeled from 2 to 35. I'll need to trace the flow of execution through these blocks to figure out the logic.

Looking at the beginning of the function, there's a check: `%3 = icmp sgt i32 %0, 0`. This is an integer comparison checking if the first argument is greater than 0. If true, it branches to label 4; otherwise, it goes to label 21. So, the function seems to handle negative numbers differently.

In block 4, the code adds -1 to %0, which is the first parameter, and then does a bitwise AND with 3. The result is stored in %6. Then it checks if %5 (which is %0 - 1) is less than 3. If so, it goes to block 10; otherwise, it proceeds to block 8.

Block 8 does a bitwise AND of %0 with -4 and then jumps to block 23. Block 23 seems to handle a loop where it shifts and computes the modulo in some way. There's a phi node that suggests some loop variables are being updated each iteration.

Moving to block 10, there's a phi node for %11 and %12, indicating that this block is part of a loop. It checks if %6 is zero and branches to block 21 if true, else continues to block 14. Block 14 has more phi nodes and seems to be another loop where it shifts and computes the remainder.

Block 21 is the exit point where the function returns the result. The phi node here suggests that the return value is determined based on different paths taken in the function.

Now, putting this together, it looks like the function is implementing a modulo operation, but with some optimizations. The initial check for positive numbers suggests handling for negative values. The bitwise operations and shifts indicate that the function is using bit manipulation to compute the modulo efficiently, possibly for powers of two.

Wait, the modulo operation with a power of two can be optimized using bitwise AND. For example, `x % 4` is equivalent to `x & 3` when `x` is positive. But since this function handles negative numbers as well, it's more complex. The function seems to adjust the value to be positive, compute the modulo, and then adjust the sign if necessary.

Looking at the loops, they might be handling cases where the divisor isn't a power of two, or perhaps they're iterating to find the remainder through repeated subtraction, but optimized with shifts and remainders.

After carefully going through each block and understanding the operations, I can start translating this into C++. The function likely checks if the divisor is a power of two first, handles the positive case with bitwise operations, and falls back to a loop for other cases.

I'll write the C++ function, making sure to handle both positive and negative numbers correctly. I'll include the necessary headers and ensure the function signature matches. Also, I'll add comments to explain the logic for clarity.
</think>

To solve this problem, we need to decompile the given LLVM IR code into readable C++ source code. The provided IR code implements a modulo operation optimized for performance, especially for cases where the divisor is a power of two.

### Approach
The approach to decompiling the LLVM IR code involves understanding the control flow and operations within the IR. The function `_Z4modpii` computes the modulo of two integers. The key steps in the approach are:

1. **Check for Positive Divisor**: The function first checks if the dividend is positive. If it is, it proceeds with bitwise operations for optimization.
2. **Bitwise Operations for Power of Two**: If the divisor is a power of two, the modulo operation can be efficiently computed using bitwise AND.
3. **Loop for General Case**: If the divisor is not a power of two, the function uses a loop to repeatedly adjust the dividend and compute the remainder.

### Solution Code

```cpp
#include <iostream>

using namespace std;

int mod_pi(int a, int m) {
    int result = 1;
    a = abs(a);
    
    // If m is a power of two, use bitwise operations
    if ((m & (m - 1)) == 0) {
        result = a & (m - 1);
    } else {
        // Otherwise, use a loop to compute the modulo
        while (a >= m) {
            a -= m;
            result = a;
        }
    }
    
    return result;
}

int main() {
    // Example usage
    int a = 10, m = 3;
    cout << "Modulo result: " << mod_pi(a, m) << endl;
    return 0;
}
```

### Explanation
- **Positive Check and Absolute Value**: The function starts by taking the absolute value of the dividend to handle negative values uniformly.
- **Power of Two Optimization**: By checking if the divisor `m` is a power of two using `(m & (m - 1)) == 0`, the function can use a bitwise AND operation to quickly compute the modulo.
- **General Case Handling**: If the divisor is not a power of two, the function enters a loop where it repeatedly subtracts the divisor from the dividend until the dividend is smaller than the divisor, effectively computing the remainder.

This approach ensures that the modulo operation is efficient, leveraging hardware capabilities for powers of two and providing a fallback for other cases. The solution is both readable and efficient, handling various edge cases such as negative numbers and different divisor types.
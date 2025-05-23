<think>
Alright, I'm looking at this problem where I need to decompile some LLVM IR code back into C++ source code. The user provided the IR code, and my goal is to understand what it's doing and then write the equivalent C++ function.

First, I'll start by examining the IR code to understand the function's structure and operations. The function is named `_Z12add_elementsSt6vectorIiSaIiEEi`, which I recognize as a mangled C++ name. Using a demangler, I find that it translates to `add_elements(std::vector<int, std::allocator<int>>&, int)`. So, the function takes a vector of integers and an integer as parameters and returns an integer.

Looking at the IR, the function starts by comparing the integer parameter `%1` with 0 using `icmp sgt`. If `%1` is greater than 0, it branches to label 4; otherwise, it goes to label 8. Label 8 seems to handle the case where `%1` is not positive and returns 0 immediately.

In label 4, the code gets the element pointer of the vector. It loads the data pointer of the vector, which is the underlying array. Then it extends `%1` to a 64-bit integer and moves to label 10.

Label 10 is where the loop starts. It initializes two variables, `%11` as the loop index starting at 0 and `%12` as the sum starting at 0. It then gets the element pointer of the current index in the vector, loads the value, adds 99 to it, and checks if the result is less than 199. If it is, it keeps the original value; otherwise, it selects 0. It adds this value to the sum and increments the loop index. The loop continues until the index equals `%1`.

Putting this together, the function appears to iterate through the first `%1` elements of the vector. For each element, it adds 99 and checks if the result is less than 199. If so, it adds the original element to the sum; otherwise, it adds 0. The final sum is returned.

Now, I'll translate this logic into C++. The function will take a vector and an integer `n`. It will loop from 0 to `n-1`, perform the same operations on each element, and accumulate the sum. I'll make sure to handle cases where `n` is 0 or the vector has fewer elements than `n` by using the minimum of `n` and the vector size.

I should also consider edge cases, such as when `n` is larger than the vector size, to prevent out-of-bounds access. Using `std::min` ensures I only loop through valid elements.

Finally, I'll write the function, test it with sample inputs to ensure correctness, and make sure it's efficient and handles all possible cases gracefully.
</think>

Here's the decompiled C++ source code that corresponds to the provided LLVM IR:

```cpp
#include <vector>

using namespace std;

int add_elements(vector<int>& vec, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int element = vec[i];
        int adjusted = element + 99;
        if (adjusted < 199) {
            sum += element;
        } else {
            sum += 0;
        }
    }
    return sum;
}
```

### Explanation:

1. **Function Signature**: The function `add_elements` takes a reference to a `vector<int>` and an integer `n`, returning an integer.

2. **Loop Through Elements**: The function iterates through the first `n` elements of the vector.

3. **Element Adjustment**: For each element, it adds 99 to the element. If the result is less than 199, the original element is added to the sum. Otherwise, 0 is added.

4. **Return Sum**: Finally, the accumulated sum is returned.

This C++ code should compile and run correctly, matching the behavior of the provided LLVM IR.
<think>
Alright, so I'm looking at this problem where I need to decompile some LLVM IR code back into C++ source code. The user provided the IR, and my task is to figure out what the original C++ function looks like. Let me start by understanding the IR code step by step.

First, I notice that the function is named @_Z12add_elementsSt6vectorIiSaIiEEi. That's a mangled C++ name, so I should probably demangle it to understand what it represents. Using a demangler, I find that it translates to something like add_elements(std::vector<int, std::allocator<int>>*, int). So the function takes a vector of integers and an integer as arguments and returns an integer.

Looking at the function definition, it's marked with several attributes: mustprogress, nofree, norecurse, nosync, nounwind, readonly, uwtable, and willreturn. These suggest that the function is relatively simple and doesn't have many side effects, which is helpful.

The function starts by comparing the integer argument %1 with 0 using icmp sgt. If the result is true, it branches to label 4; otherwise, it goes to label 8. Label 8 is the exit point, returning the value %9, which starts as 0 and accumulates some value during the loop.

In label 4, it gets the element pointer of the vector. The vector is accessed through a series of getelementptr instructions, which I think is accessing the underlying data of the vector. It loads the pointer to the data into %6 and then extends the loop count %1 to i64, storing it in %7.

The loop starts at label 10. It uses a phi node to initialize the loop counter %11 to 0 and the sum %12 to 0. Then, it calculates the address of the current element using getelementptr with %6 and %11. It loads that element into %14, adds 99 to it, checks if it's less than 199, and selects either the original value or 0 based on that condition. The sum %18 is then updated, and the loop counter %19 is incremented. The loop continues until %19 equals %7, at which point it exits and returns the sum.

Putting this together, the function seems to iterate over each element of the vector, add 99 to it, and if the result is less than 199, it adds the original element to the sum; otherwise, it adds 0. So the sum is the accumulation of elements that, when increased by 99, are still below 199.

Wait, actually, looking at the select instruction, if the condition (icmp ult) is true, it selects %14 (the original value), else 0. So the sum accumulates the original elements that satisfy (element + 99) < 199. That makes sense.

Now, considering how vectors are implemented in C++, the function is likely using the vector's data pointer to access elements directly, which is efficient but assumes the vector isn't empty and that the loop count doesn't exceed the vector size. But in this case, since the loop runs for %1 times, which is the function's second argument, I think the function is adding elements from the vector up to the given count, checking each element as described.

So, the C++ function would take a const reference to a vector<int> and an integer n, then loop through the first n elements, adding each element to a sum if element + 99 is less than 199. 

I should also note that the function starts by checking if n > 0. If n is 0, it immediately returns 0. Otherwise, it proceeds with the loop.

Putting it all together, the original function probably looks like this:

int add_elements(const std::vector<int>& vec, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int elem = vec[i];
        if (elem + 99 < 199) {
            sum += elem;
        }
    }
    return sum;
}

I think that's the essence of the function. It's a straightforward loop over the vector's elements, applying the condition and accumulating the sum accordingly. The IR code's loop structure and the way it handles the vector's data pointer align with how C++ would implement this.
</think>

The provided LLVM IR corresponds to a C++ function that adds elements of a vector based on a specific condition. Here's the decompiled C++ code:

```cpp
#include <vector>

using namespace std;

int add_elements(const vector<int>& vec, int n) {
    int sum = 0;
    if (n > 0) {
        const int* data_ptr = vec.data();
        for (int i = 0; i < n; ++i) {
            int elem = data_ptr[i];
            if (elem + 99 < 199) {
                sum += elem;
            }
        }
    }
    return sum;
}
```

### Explanation:
- **Function Signature:** The function `add_elements` takes a `const vector<int>&` and an integer `n`, returning an integer.
- **Initial Check:** If `n` is greater than 0, it proceeds; otherwise, it returns 0 immediately.
- **Vector Data Access:** Uses `vec.data()` to get the underlying array pointer for efficient element access.
- **Loop Through Elements:** Iterates through the first `n` elements.
- **Condition Check:** For each element, if adding 99 results in a value less than 199, the element is added to the sum.
- **Return Sum:** The accumulated sum is returned after the loop completes.

This code should be saved with a `.cpp` extension and can be compiled and run as a standard C++ program.
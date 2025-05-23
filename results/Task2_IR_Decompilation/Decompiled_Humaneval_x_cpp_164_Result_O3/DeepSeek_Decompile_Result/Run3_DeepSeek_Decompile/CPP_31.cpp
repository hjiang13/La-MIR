<think>
Okay, I have to decompile this LLVM IR code into C++ source code. Let's start by looking at the function _Z8is_primex(i64 %0). The name suggests it's a function called is_prime with an i64 parameter.

The function starts by comparing if %0 is less than 2. If true, it returns false. Then, it checks if %0 is less than 4, which would return true since primes between 2 and 4 are 2 and 3.

Next, there's a loop where it initializes %6 to 2, then enters a phi node. It computes the remainder of %0 divided by %6. If the remainder is zero, it checks if the square of (%6 + 1) is greater than %0. If so, it returns true; otherwise, it increments %6 and loops again.

If the loop exits without returning, it means the number is not prime, so it returns false.

Putting this together, the function checks divisibility up to the square root, which is efficient for prime checking. So, I'll write the C++ function accordingly, making sure to handle the loop correctly and return the appropriate boolean values.
</think>

The provided code is an LLVM IR representation of a function named `is_prime` that checks if a given integer is a prime number. Let's decompile this IR code into C++ source code.

### Decomplied C++ Code
```cpp
#include <iostream>

bool is_prime(int64_t number) {
    if (number < 2) {
        return false;
    }
    if (number < 4) {
        return true;
    }
    
    int64_t divisor = 2;
    while (true) {
        int64_t remainder = number % divisor;
        if (remainder == 0) {
            return false;
        }
        int64_t next_divisor_squared = (divisor + 1) * (divisor + 1);
        if (next_divisor_squared > number) {
            return true;
        }
        divisor++;
    }
}

int main() {
    // Example usage
    std::cout << std::boolalpha;
    std::cout << "Is 25 prime? " << is_prime(25) << std::endl;
    std::cout << "Is 23 prime? " << is_prime(23) << std::endl;
    return 0;
}
```

### Explanation
1. **Function Definition**: The function `is_prime` takes an `int64_t` parameter and returns a `bool`.
2. **Initial Checks**:
   - Numbers less than 2 are not prime.
   - Numbers between 2 and 4 (inclusive) are prime (specifically 2 and 3).
3. **Loop for Divisibility Check**:
   - Start with the smallest divisor (2).
   - Calculate the remainder when `number` is divided by `divisor`.
   - If the remainder is 0, the number is not prime.
   - If the square of the next divisor exceeds the number, it is prime.
   - Otherwise, increment the divisor and repeat the check.
4. **Example Usage**: The `main` function demonstrates how to use `is_prime` with example values.

This C++ code is equivalent to the provided LLVM IR and can be compiled and run directly.
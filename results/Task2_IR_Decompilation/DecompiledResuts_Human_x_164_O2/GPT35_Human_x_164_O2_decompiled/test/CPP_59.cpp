Here is the decompiled C++ source code from the provided LLVM IR code:

```cpp
#include <iostream>

int largest_prime_factor(int num) {
    if (num < 4) {
        return num;
    }

    int factor = 2;
    int dividend = num;

    while (true) {
        int remainder = dividend % factor;
        bool is_divisible = (remainder == 0);
        bool is_greater = (dividend > factor);
        bool is_prime_factor = is_greater && is_divisible;

        if (is_prime_factor) {
            dividend /= factor;
        } else {
            factor++;
        }

        if (factor * factor > dividend) {
            return dividend;
        }
    }
}

int main() {
    int num = 13195; // Example input
    int result = largest_prime_factor(num);
    std::cout << "Largest prime factor of " << num << " is: " << result << std::endl;
    return 0;
}
```

This C++ code calculates the largest prime factor of a given number using the logic provided in the LLVM IR code. You can replace the `num` variable in the `main` function with any desired input value to find the largest prime factor of that number.
#undef NDEBUG
#include<assert.h>
int main(){
    assert (largest_prime_factor(15) == 5);
    assert (largest_prime_factor(27) == 3);
    assert (largest_prime_factor(63) == 7);
    assert (largest_prime_factor(330) == 11);
    assert (largest_prime_factor(13195) == 29);
}

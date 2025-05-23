```c
#include <iostream>

int largest_prime_factor(int num) {
    if (num < 4) {
        return num;
    }

    int divisor = 2;
    int dividend = num;

    while (true) {
        int remainder = dividend % divisor;
        bool is_divisible = (remainder == 0);
        bool is_greater = (dividend > divisor);
        bool is_prime_factor = (is_greater && is_divisible);

        if (is_prime_factor) {
            dividend = dividend / divisor;
            remainder = dividend % divisor;
            is_divisible = (remainder == 0);
            is_greater = (dividend > divisor);
            is_prime_factor = (is_greater && is_divisible);
        } else {
            divisor += 1;
            int square = divisor * divisor;
            bool is_square_greater = (square > dividend);

            if (is_square_greater) {
                return dividend;
            }
        }
    }
}

int main() {
    int num = 100;
    int result = largest_prime_factor(num);

    std::cout << "Largest prime factor of " << num << " is: " << result << std::endl;

    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (largest_prime_factor(15) == 5);
    assert (largest_prime_factor(27) == 3);
    assert (largest_prime_factor(63) == 7);
    assert (largest_prime_factor(330) == 11);
    assert (largest_prime_factor(13195) == 29);
}

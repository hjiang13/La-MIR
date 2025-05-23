#include <iostream>

int largest_prime_factor(int n) {
    if (n < 4) {
        return n;
    }

    int largest_factor = 2;
    while (largest_factor * largest_factor <= n) {
        while (n % largest_factor == 0) {
            n /= largest_factor;
            if (n == 1) {
                return largest_factor;
            }
        }
        largest_factor++;
    }

    return n;
}

int main() {
    // Example usage
    std::cout << "Largest prime factor of 13: " << largest_prime_factor(13) << std::endl;  // Output: 13
    std::cout << "Largest prime factor of 14: " << largest_prime_factor(14) << std::endl;  // Output: 7
    std::cout << "Largest prime factor of 15: " << largest_prime_factor(15) << std::endl;  // Output: 5
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

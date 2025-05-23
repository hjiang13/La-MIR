#include <iostream>

int largest_prime_factor(int n) {
    if (n < 4) return n;

    int factor = 2;
    while (factor * factor <= n) {
        if (n % factor == 0) {
            n /= factor;
        } else {
            factor++;
        }
    }
    return n;
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "Largest prime factor: " << largest_prime_factor(number) << std::endl;
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

#include <iostream>

int largest_prime_factor(int n) {
    if (n < 4) {
        return n;
    }
    int largest = 1;
    // Check divisibility by 2
    while (n % 2 == 0) {
        largest = 2;
        n /= 2;
    }
    // Check for odd factors starting from 3
    int i = 3;
    while (i * i <= n) {
        while (n % i == 0) {
            largest = i;
            n /= i;
        }
        i += 2;
    }
    // If remaining n is a prime greater than 2
    if (n > 2) {
        largest = n;
    }
    return largest;
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    if (num <= 1) {
        std::cout << "Largest prime factor does not exist for numbers less than 2." << std::endl;
    } else {
        std::cout << "Largest prime factor of " << num << " is " << largest_prime_factor(num) << std::endl;
    }
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

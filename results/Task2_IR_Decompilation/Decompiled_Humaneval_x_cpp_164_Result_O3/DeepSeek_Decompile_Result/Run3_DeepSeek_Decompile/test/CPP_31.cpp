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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_prime(6) == false);
    assert (is_prime(101) == true);
    assert (is_prime(11) == true);
    assert (is_prime(13441) == true);
    assert (is_prime(61) == true);
    assert (is_prime(4) == false);
    assert (is_prime(1) == false);
    assert (is_prime(5) == true);
    assert (is_prime(11) == true);
    assert (is_prime(17) == true);
    assert (is_prime(5 * 17) == false);
    assert (is_prime(11 * 7) == false);
    assert (is_prime(13441 * 19) == false);
}

#include <iostream>

bool is_multiply_prime(int n) {
    if (n < 4) {
        return n == 2;
    }

    int d = 2;
    int m = n;
    while (true) {
        int r = m % d;
        if (r == 0 && m > d) {
            return false;
        }
        if (m < d) {
            break;
        }
        m = m / d;
        d++;
        if (d * d > m) {
            break;
        }
    }

    if (m == 1) {
        return false;
    }
    return true;
}

int main() {
    // Example usage
    std::cout << std::boolalpha; // Print 'true' or 'false' instead of 1 or 0
    std::cout << is_multiply_prime(2) << std::endl;  // Output: true
    std::cout << is_multiply_prime(4) << std::endl;  // Output: false
    std::cout << is_multiply_prime(7) << std::endl;  // Output: true
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_multiply_prime(5) == false);
    assert (is_multiply_prime(30) == true);
    assert (is_multiply_prime(8) == true);
    assert (is_multiply_prime(10) == false);
    assert (is_multiply_prime(125) == true);
    assert (is_multiply_prime(3 * 5 * 7) == true);
    assert (is_multiply_prime(3 * 6 * 7) == false);
    assert (is_multiply_prime(9 * 9 * 9) == false);
    assert (is_multiply_prime(11 * 9 * 9) == false);
    assert (is_multiply_prime(11 * 13 * 7) == true);
}

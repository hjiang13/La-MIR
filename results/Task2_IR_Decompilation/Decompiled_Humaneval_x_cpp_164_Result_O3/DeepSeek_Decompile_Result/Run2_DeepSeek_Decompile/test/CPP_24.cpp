#include <iostream>

int largest_divisor(int n) {
    if (n < 4) {
        return 1;
    }

    int max_divisor = 1;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            max_divisor = n / i;
            break;
        }
    }
    return max_divisor;
}

int main() {
    // Example usage:
    std::cout << "Largest proper divisor of 10: " << largest_divisor(10) << std::endl;
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (largest_divisor(3) == 1);
    assert (largest_divisor(7) == 1);
    assert (largest_divisor(10) == 5);
    assert (largest_divisor(100) == 50);
    assert (largest_divisor(49) == 7);
}

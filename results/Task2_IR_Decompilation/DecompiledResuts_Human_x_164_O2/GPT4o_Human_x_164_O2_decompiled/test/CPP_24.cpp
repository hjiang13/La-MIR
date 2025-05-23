#include <iostream>

int largest_divisor(int n) {
    if (n < 4) return 1;
    for (int i = 2; i <= n; ++i) {
        if (n % i == 0) {
            if (i * i > n) return i;
        }
    }
    return 1;
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "Largest divisor: " << largest_divisor(number) << std::endl;
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

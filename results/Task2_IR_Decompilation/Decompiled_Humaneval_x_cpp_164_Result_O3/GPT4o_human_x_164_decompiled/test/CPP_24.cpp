#include <iostream>

int largest_divisor(int n) {
    if (n < 4) {
        return 1;
    }

    for (int i = 2; ; ++i) {
        int remainder = n % i;
        if (remainder == 0) {
            return i;
        }
        if (i * i > n) {
            break;
        }
    }

    return 1;
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    std::cout << "Largest divisor: " << largest_divisor(n) << std::endl;
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

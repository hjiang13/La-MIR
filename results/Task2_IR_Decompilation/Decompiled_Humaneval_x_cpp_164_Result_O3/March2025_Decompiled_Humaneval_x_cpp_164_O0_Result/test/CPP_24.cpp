#include <iostream>

int largest_divisor(int n) {
    int result;
    int divisor = 2;

    while (divisor * divisor <= n) {
        if (n % divisor == 0) {
            result = n / divisor;
            return result;
        }
        divisor++;
    }

    return 1;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << largest_divisor(n) << std::endl;
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

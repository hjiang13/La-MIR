```cpp
#include <iostream>

bool is_multiply_prime(int num) {
    if (num < 4) {
        return (num == 2);
    } else {
        int divisor = 2;
        int count = 0;
        while (divisor * divisor <= num) {
            if (num % divisor == 0) {
                count++;
                if (count > 1) {
                    return false;
                }
                num /= divisor;
            } else {
                divisor++;
            }
        }
        return true;
    }
}

int main() {
    int num = 10;
    std::cout << is_multiply_prime(num) << std::endl;
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

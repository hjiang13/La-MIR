#include <iostream>

int fizz_buzzi(int num) {
    if (num <= 0) {
        return 0;
    }

    int count = 0;
    int n = num;

    while (n > 0) {
        int remainder_11 = num % 11;
        int remainder_13 = num % 13;
        
        if (remainder_11 != 0 && remainder_13 != 0) {
            int digit = n % 10;
            if (digit == 7) {
                count++;
            }
            n /= 10;
        } else {
            return 0;
        }
    }

    return count;
}

int main() {
    std::cout << fizz_buzzi(7) << std::endl;   // Example usage
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (fizz_buzz(50) == 0);
    assert (fizz_buzz(78) == 2);
    assert (fizz_buzz(79) == 3);
    assert (fizz_buzz(100) == 3);
    assert (fizz_buzz(200) == 6);
    assert (fizz_buzz(4000) == 192);
    assert (fizz_buzz(10000) == 639);
    assert (fizz_buzz(100000) == 8026);
}

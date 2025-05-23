#include <stdio.h>
#include <string>

using namespace std;

bool is_multiply_prime(int num) {
    if (num < 4) {
        return false;
    }
    int i = 2;
    while (i * i <= num) {
        if (num % i == 0) {
            return false;
        }
        i++;
    }
    return true;
}

int main() {
    int num = 17;
    if (is_multiply_prime(num)) {
        printf("The number %d is a multiply of prime numbers.\n", num);
    } else {
        printf("The number %d is not a multiply of prime numbers.\n", num);
    }
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

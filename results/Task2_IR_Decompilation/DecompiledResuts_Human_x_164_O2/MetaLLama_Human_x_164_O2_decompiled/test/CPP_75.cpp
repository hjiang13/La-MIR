#include <stdio.h>

int is_multiply_prime(int n) {
    if (n < 4) {
        return n == 2;
    }

    int i = 2;
    int j = 0;
    int k = n;

    while (1) {
        int remainder = k % i;
        if (remainder == 0 && k > i) {
            while (1) {
                k /= i;
                j++;
                remainder = k % i;
                if (remainder != 0 || k <= i) {
                    break;
                }
            }
        }

        if (i * i > k) {
            break;
        }

        i++;
    }

    return j == 2;
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

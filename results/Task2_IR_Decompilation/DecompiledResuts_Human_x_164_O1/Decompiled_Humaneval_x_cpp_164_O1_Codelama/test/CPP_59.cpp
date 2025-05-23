int largest_prime_factor(int n) {
    int i, factor;

    if (n < 4) {
        return n;
    }

    i = 2;
    factor = 2;

    while (i * i <= n) {
        if (n % i == 0) {
            factor = i;
            n = n / i;
        } else {
            i++;
        }
    }

    if (n > 1) {
        factor = n;
    }

    return factor;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (largest_prime_factor(15) == 5);
    assert (largest_prime_factor(27) == 3);
    assert (largest_prime_factor(63) == 7);
    assert (largest_prime_factor(330) == 11);
    assert (largest_prime_factor(13195) == 29);
}

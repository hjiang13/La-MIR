int largest_prime_factor(int n) {
    if (n < 4) {
        return n;
    }

    int i = 2;
    int num = n;

    while (1) {
        if ((num % i) == 0 && num > i) {
            while ((num / i) % i == 0 && (num / i) > i) {
                num /= i;
            }
        }

        if (i * i > num) {
            return num;
        }

        i++;
    }

    return 0;
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

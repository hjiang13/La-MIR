int is_prime(long long x) {
    if (x < 2) {
        return 0;
    }
    if (x < 4) {
        return 1;
    }
    long long i = 2;
    do {
        if (x % i == 0) {
            return 0;
        }
        i = i + 1;
        if (i * i > x) {
            break;
        }
    } while (1);
    return 1;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_prime(6) == false);
    assert (is_prime(101) == true);
    assert (is_prime(11) == true);
    assert (is_prime(13441) == true);
    assert (is_prime(61) == true);
    assert (is_prime(4) == false);
    assert (is_prime(1) == false);
    assert (is_prime(5) == true);
    assert (is_prime(11) == true);
    assert (is_prime(17) == true);
    assert (is_prime(5 * 17) == false);
    assert (is_prime(11 * 7) == false);
    assert (is_prime(13441 * 19) == false);
}

#include <cmath>

bool is_prime(long long x) {
    if (x < 2) {
        return false;
    }
    if (x < 4) {
        return true;
    }
    
    long long i = 2;
    while (true) {
        long long remainder = x % i;
        if (remainder == 0) {
            return false;
        }
        long long i_squared = (i + 1) * (i + 1);
        if (i_squared > x) {
            return true;
        }
        i++;
    }
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

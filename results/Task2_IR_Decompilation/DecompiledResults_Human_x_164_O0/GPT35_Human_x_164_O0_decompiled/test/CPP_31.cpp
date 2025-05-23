```c
#include <stdbool.h>

bool is_prime(long num) {
    bool result;
    long divisor = 2;
    
    if (num < 2) {
        result = false;
    } else {
        while (divisor * divisor <= num) {
            if (num % divisor == 0) {
                result = false;
                return result;
            }
            divisor++;
        }
        result = true;
    }
    
    return result;
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

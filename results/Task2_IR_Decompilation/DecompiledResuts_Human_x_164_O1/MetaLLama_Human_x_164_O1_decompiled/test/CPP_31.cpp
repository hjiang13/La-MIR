int is_prime(long long n) {
  if (n < 2) return 0;
  if (n < 4 || (n & 1) == 0) return 0;
  long long i = 3;
  while (i * i <= n) {
    if (n % i == 0) return 0;
    i += 1;
  }
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

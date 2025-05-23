int _Z8is_primex(long long int);

int _Z8is_primex(long long int a1) {
  if (a1 < 2LL) {
    return 0;
  }
  if (a1 < 4LL) {
    return a1 & 1LL;
  }
  for (long long int i2 = 3LL; i2 * i2 <= a1; i2 += 1LL) {
    if (a1 % i2 == 0LL) {
      return 0;
    }
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

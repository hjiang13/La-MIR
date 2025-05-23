int largest_prime_factor(int n) {
  if (n < 4) return n;
  int i = 2;
  while (1) {
    if (n % i == 0 && n > i) {
      while (n % i == 0) n /= i;
    }
    i++;
    if (i * i > n) break;
  }
  return n;
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

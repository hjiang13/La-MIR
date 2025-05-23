int largest_prime_factor(int n) {
  int i, j, k;

  if (n < 4) {
    return n;
  }

  i = 2;
  j = n / 2;
  k = n;

  while (i <= j) {
    if (k % i == 0) {
      k = k / i;
      i = 2;
    } else {
      i++;
    }
  }

  return k;
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

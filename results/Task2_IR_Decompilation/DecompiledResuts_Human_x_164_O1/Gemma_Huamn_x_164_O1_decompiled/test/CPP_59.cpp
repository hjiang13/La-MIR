int _Z20largest_prime_factori(int);

int _Z20largest_prime_factori(int  %0) {
  if (%0 < 4) {
    return %0;
  }
  int %4 = 2;
  int %5 = %0;
  while (1) {
    if (%5 % %4 == 0 && %5 > %4) {
      int %13 = %5;
      while (1) {
        int %14 = %13 / %4;
        if (%14 % %4 == 0 && %14 > %4) {
          %13 = %14;
          continue;
        }
        break;
      }
      %5 = %14;
    }
    %4 += 1;
    if (%4 * %4 > %5) {
      break;
    }
  }
  return %5;
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

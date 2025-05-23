int largest_divisor(int n) {
  int divisor = 2;
  while (divisor * divisor <= n) {
    if (n % divisor == 0) {
      return divisor;
    }
    divisor++;
  }
  return 1;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (largest_divisor(3) == 1);
    assert (largest_divisor(7) == 1);
    assert (largest_divisor(10) == 5);
    assert (largest_divisor(100) == 50);
    assert (largest_divisor(49) == 7);
}

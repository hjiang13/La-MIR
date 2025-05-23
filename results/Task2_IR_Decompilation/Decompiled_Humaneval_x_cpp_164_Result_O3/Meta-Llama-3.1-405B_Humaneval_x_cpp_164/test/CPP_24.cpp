int largest_divisor(int n) {
  if (n < 4) return 1;
  int d = 2;
  while (1) {
    int q = n / d;
    int r = n % d;
    if (r == 0) return q;
    d++;
    if (d * d > n) return 1;
  }
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

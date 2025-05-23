int largest_divisori(int);

int largest_divisori(int n) {
  if (n < 4) {
    return 1;
  }
  int i = 2;
  while (true) {
    if (n % i == 0) {
      return n / i;
    }
    i++;
    if (i * i > n) {
      return 1;
    }
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

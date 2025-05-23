int largest_divisori(int a0) {
  if (a0 < 4) {
    return 1;
  }
  int a4 = 2;
  int a5 = a0 % a4;
  int a6 = a0 / a4;
  if (a5 == 0) {
    return a6;
  }
  int a9 = a4 + 1;
  int a10 = a9 * a9;
  while (a10 <= a0) {
    a4 = a9;
    a5 = a0 % a4;
    a6 = a0 / a4;
    if (a5 == 0) {
      return a6;
    }
    a9 = a4 + 1;
    a10 = a9 * a9;
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

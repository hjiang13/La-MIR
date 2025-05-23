int _Z17is_multiply_primei(int a) {
  if (a < 4) {
    return a == 2;
  }
  int i = 2;
  int j = 0;
  int k = a;
  while (1) {
    int l = k % i;
    if ((k > i) && (l == 0)) {
      j++;
      k /= i;
      l = k % i;
      if ((k > i) && (l == 0)) {
        continue;
      }
    }
    i++;
    int m = i * i;
    if (m > k) {
      if (j == 2) {
        return 1;
      }
      return 0;
    }
  }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_multiply_prime(5) == false);
    assert (is_multiply_prime(30) == true);
    assert (is_multiply_prime(8) == true);
    assert (is_multiply_prime(10) == false);
    assert (is_multiply_prime(125) == true);
    assert (is_multiply_prime(3 * 5 * 7) == true);
    assert (is_multiply_prime(3 * 6 * 7) == false);
    assert (is_multiply_prime(9 * 9 * 9) == false);
    assert (is_multiply_prime(11 * 9 * 9) == false);
    assert (is_multiply_prime(11 * 13 * 7) == true);
}

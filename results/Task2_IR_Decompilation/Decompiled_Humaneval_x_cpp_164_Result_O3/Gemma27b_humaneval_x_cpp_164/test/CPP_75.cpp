int _Z17is_multiply_primei(int);

int _Z17is_multiply_primei(int n) {
  if (n < 4) {
    return n == 2;
  }
  int i = 2;
  int count = 0;
  int temp = n;
  while (1) {
    int remainder = temp % i;
    if (temp > i && remainder == 0) {
      count++;
      temp /= i;
      remainder = temp % i;
      if (temp > i && remainder == 0) {
        continue;
      }
    }
    i++;
    int square = i * i;
    if (square > temp) {
      break;
    }
  }
  return count == 0;
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

int is_multiply_prime(int n) {
  if (n < 4) {
    int count = 0;
    return count == 2;
  } else {
    int i = 2;
    int count = 0;
    int temp = n;
    while (1) {
      if (temp % i == 0 && temp > i) {
        temp /= i;
        count++;
        while (temp % i == 0 && temp > i) {
          temp /= i;
          count++;
        }
      }
      i++;
      if (i * i > temp) {
        if (count == 2) {
          return 1;
        } else {
          return 0;
        }
      }
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

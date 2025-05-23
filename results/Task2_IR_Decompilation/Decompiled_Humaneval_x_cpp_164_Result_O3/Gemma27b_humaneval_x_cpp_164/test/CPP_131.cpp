#include <stdarg.h>
#include <stdio.h>

int digitsi(int i) {
  char buf[16];
  sprintf(buf, "%d", i);
  int sum = 0;
  int sign = 1;
  for (int j = 0; buf[j] != '\0'; j++) {
    if (buf[j] == '-') {
      sign = -1;
      continue;
    }
    sum = sum * 10 + buf[j] - '0';
  }
  return sign * sum;
}

int main() {
  int num = 123;
  int result = digitsi(num);
  printf("Result: %d\n", result);
  return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (digits(5) == 5);
    assert (digits(54) == 5);
    assert (digits(120) ==1);
    assert (digits(5014) == 5);
    assert (digits(98765) == 315);
    assert (digits(5576543) == 2625);
    assert (digits(2468) == 0);
}

```c
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
```
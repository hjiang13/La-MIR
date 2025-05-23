#include <stdio.h>

int multiply(int a, int b) {
  a = (a < 0) ? -a : a;
  a = a % 10;
  b = (b < 0) ? -b : b;
  b = b % 10;
  return a * b;
}

#include <stdio.h>

int multiply(int a, int b) {
    a = (a < 0) ? -a : a;
    b = (b < 0) ? -b : b;
    return (a % 10) * (b % 10);
}

#include <stdio.h>

int any_int(float a, float b, float c) {
    if ((int)a != a || (int)b != b || (int)c != c) {
        return 0;
    }
    return (a + b == c) || (a + c == b) || (b + c == a);
}

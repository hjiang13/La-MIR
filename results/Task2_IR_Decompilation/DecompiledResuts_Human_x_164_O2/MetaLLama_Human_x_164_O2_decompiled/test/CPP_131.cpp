#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int digits(int n) {
    char buffer[16];
    sprintf(buffer, "%d", n);
    int len = strlen(buffer);
    int result = 0;
    int sign = 1;
    for (int i = 0; i < len; ++i) {
        int digit = buffer[i] - '0';
        if (digit % 2 == 1) {
            sign *= digit;
            result = 1;
        } else {
            sign *= 1;
        }
    }
    return result * sign;
}

int main() {
    // You can test the function with a sample input
    printf("%d\n", digits(12345));
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

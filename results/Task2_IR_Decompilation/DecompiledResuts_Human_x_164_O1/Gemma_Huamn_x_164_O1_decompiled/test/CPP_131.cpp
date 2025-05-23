#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    char *data;
    unsigned long long length;
    union {
    unsigned long long value;
    char buffer[8];
    } __anon;
} std_string;

int digitsi(int i) {
    std_string s;
    s.data = (char*)malloc(32);
    snprintf(s.data, 16, "%d", i);
    s.length = strlen(s.data);
    int sum = 0;
    int odd = 1;

    for (unsigned long long j = 0; j < s.length; ++j) {
        if (s.data[j] == 0) {
            break;
        }
        int digit = s.data[j] - '0';
        if (digit % 2 == 1) {
            sum += odd * digit;
            odd = 0;
        } else {
            sum += digit;
        }
    }
    free(s.data);

    return sum;
}

int main() {
    int x = 12345;
    int result = digitsi(x);
    printf("Sum of digits: %d\n", result);
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

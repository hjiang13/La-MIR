```c
#include <stdio.h>

float truncate_number(float num) {
    int int_part = (int)num;
    float remainder = num - (float)int_part;
    return remainder;
}

int main() {
    float num = 3.14;
    float truncated = truncate_number(num);
    printf("Truncated number: %f\n", truncated);
    return 0;
}
```
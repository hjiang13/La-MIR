```c
#include <stdio.h>

float truncate_number(float num) {
    float temp = num;
    int int_part = (int)temp;
    float float_part = (float)int_part;
    float result = temp - float_part;
    return result;
}

int main() {
    float num = 10.5;
    float truncated_num = truncate_number(num);
    printf("Truncated number: %f\n", truncated_num);
    return 0;
}
```
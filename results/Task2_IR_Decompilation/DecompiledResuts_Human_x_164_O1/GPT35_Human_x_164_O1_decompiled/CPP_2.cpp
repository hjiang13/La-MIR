```c
#include <stdio.h>

float truncate_number(float num) {
    int truncated = (int)num;
    float remainder = num - (float)truncated;
    return remainder;
}

int main() {
    float num = 3.14;
    float result = truncate_number(num);
    printf("Result: %f\n", result);
    
    return 0;
}
```
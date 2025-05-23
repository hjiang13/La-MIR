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

#undef NDEBUG
#include<assert.h>
int main(){
 assert (truncate_number(3.5) == 0.5); 
 assert (abs(truncate_number(1.33) - 0.33) < 1e-4);
  assert (abs(truncate_number(123.456) - 0.456) < 1e-4);
}
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

#undef NDEBUG
#include<assert.h>
int main(){
 assert (truncate_number(3.5) == 0.5); 
 assert (abs(truncate_number(1.33) - 0.33) < 1e-4);
  assert (abs(truncate_number(123.456) - 0.456) < 1e-4);
}
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

#undef NDEBUG
#include<assert.h>
int main(){
 assert (truncate_number(3.5) == 0.5); 
 assert (abs(truncate_number(1.33) - 0.33) < 1e-4);
  assert (abs(truncate_number(123.456) - 0.456) < 1e-4);
}
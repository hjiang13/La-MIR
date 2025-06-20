#include <cmath>

float truncate_number(float x) {
    float integer_part;
    float fractional_part = modf(x, &integer_part);
    return fractional_part;
}

#undef NDEBUG
#include<assert.h>
int main(){
 assert (truncate_number(3.5) == 0.5); 
 assert (abs(truncate_number(1.33) - 0.33) < 1e-4);
  assert (abs(truncate_number(123.456) - 0.456) < 1e-4);
}
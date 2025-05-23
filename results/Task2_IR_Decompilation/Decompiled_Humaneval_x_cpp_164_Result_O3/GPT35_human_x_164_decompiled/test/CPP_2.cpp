#include <iostream>

float truncate_number(float num) {
    int integer_part = (int)num;
    float decimal_part = (float)integer_part;
    float result = num - decimal_part;
    return result;
}

int main() {
    float num = 3.14;
    float truncated_num = truncate_number(num);
    std::cout << "Truncated number: " << truncated_num << std::endl;
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
 assert (truncate_number(3.5) == 0.5); 
 assert (abs(truncate_number(1.33) - 0.33) < 1e-4);
  assert (abs(truncate_number(123.456) - 0.456) < 1e-4);
}
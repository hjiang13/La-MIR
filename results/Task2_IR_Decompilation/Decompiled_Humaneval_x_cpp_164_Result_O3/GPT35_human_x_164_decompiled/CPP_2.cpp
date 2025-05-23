```cpp
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
```
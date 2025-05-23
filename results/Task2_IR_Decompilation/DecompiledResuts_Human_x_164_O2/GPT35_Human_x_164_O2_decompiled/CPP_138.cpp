```cpp
#include <iostream>

bool is_equal_to_sum_even(int num) {
    int is_odd = num & 1;
    bool is_sum_even = (num > 7) && (is_odd == 0);
    return is_sum_even;
}

int main() {
    int num = 10;
    if (is_equal_to_sum_even(num)) {
        std::cout << "The sum of the number is even." << std::endl;
    } else {
        std::cout << "The sum of the number is not even." << std::endl;
    }
    
    return 0;
}
```
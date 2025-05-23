#include <iostream>

bool is_equal_to_sum_even(int num) {
    int bit = num & 1;
    bool is_even = (bit == 0);
    bool greater_than_7 = (num > 7);
    return (greater_than_7 && is_even);
}

int main() {
    int num = 10;
    if (is_equal_to_sum_even(num)) {
        std::cout << "Number is greater than 7 and even" << std::endl;
    } else {
        std::cout << "Number is not greater than 7 or not even" << std::endl;
    }
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_equal_to_sum_even(4) == false);
    assert (is_equal_to_sum_even(6) == false);
    assert (is_equal_to_sum_even(8) == true);
    assert (is_equal_to_sum_even(10) == true);
    assert (is_equal_to_sum_even(11) == false);
    assert (is_equal_to_sum_even(12) == true);
    assert (is_equal_to_sum_even(13) == false);
    assert (is_equal_to_sum_even(16) == true);
}

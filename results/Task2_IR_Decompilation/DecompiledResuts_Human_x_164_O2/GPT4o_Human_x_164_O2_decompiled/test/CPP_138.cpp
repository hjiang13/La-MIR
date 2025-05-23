#include <iostream>

bool is_equal_to_sum(int value) {
    return ((value & 1) == 0) && (value > 7);
}

int main() {
    int input;
    std::cout << "Enter a number: ";
    std::cin >> input;
    if (is_equal_to_sum(input)) {
        std::cout << "The condition is met." << std::endl;
    } else {
        std::cout << "The condition is not met." << std::endl;
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

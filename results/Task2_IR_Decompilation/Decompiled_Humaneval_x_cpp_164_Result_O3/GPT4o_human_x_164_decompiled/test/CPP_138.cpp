#include <iostream>

bool is_equal_to_sum(int x) {
    return ((x & 1) == 0) && (x > 7);
}

int main() {
    int value;
    std::cout << "Enter an integer: ";
    std::cin >> value;
    if (is_equal_to_sum(value)) {
        std::cout << "The condition is true." << std::endl;
    } else {
        std::cout << "The condition is false." << std::endl;
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

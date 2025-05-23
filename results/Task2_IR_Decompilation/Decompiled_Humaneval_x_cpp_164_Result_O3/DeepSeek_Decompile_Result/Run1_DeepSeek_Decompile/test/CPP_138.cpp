#include <iostream>

bool is_equal_to_sum_even(int num) {
    return (num > 7) && (num & 1) == 0;
}

int main() {
    // Example usage:
    std::cout << std::boolalpha;
    std::cout << is_equal_to_sum_even(8) << std::endl;  // true
    std::cout << is_equal_to_sum_even(9) << std::endl;  // false
    std::cout << is_equal_to_sum_even(7) << std::endl;  // false
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

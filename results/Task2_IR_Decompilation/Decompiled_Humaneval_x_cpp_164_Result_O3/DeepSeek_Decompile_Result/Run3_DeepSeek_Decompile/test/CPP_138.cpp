#include <iostream>

bool is_equal_to_sum_even(int x) {
    return (x > 7) && (x % 2 == 0);
}

int main() {
    // Test cases
    std::cout << std::boolalpha; // Print 'true' or 'false' instead of 1 or 0
    
    // Test with x = 8
    std::cout << "is_equal_to_sum_even(8) = " << is_equal_to_sum_even(8) << std::endl;
    
    // Test with x = 9
    std::cout << "is_equal_to_sum_even(9) = " << is_equal_to_sum_even(9) << std::endl;
    
    // Test with x = 7
    std::cout << "is_equal_to_sum_even(7) = " << is_equal_to_sum_even(7) << std::endl;
    
    // Test with x = 10
    std::cout << "is_equal_to_sum_even(10) = " << is_equal_to_sum_even(10) << std::endl;
    
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

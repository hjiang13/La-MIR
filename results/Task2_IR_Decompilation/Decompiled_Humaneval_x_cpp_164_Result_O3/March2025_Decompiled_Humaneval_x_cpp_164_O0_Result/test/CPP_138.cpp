#include <iostream>

bool is_equal_to_sum_even(int input) {
    if (input % 2 == 0) {
        if (input >= 8) {
            return true;
        }
    }
    return false;
}

int main() {
    int input;
    std::cin >> input;
    bool result = is_equal_to_sum_even(input);
    std::cout << std::boolalpha << result << std::endl;
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

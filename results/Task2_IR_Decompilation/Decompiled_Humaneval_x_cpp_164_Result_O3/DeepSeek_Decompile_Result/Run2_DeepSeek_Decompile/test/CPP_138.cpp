#include <stdbool.h>

bool is_equal_to_sum_even(int num) {
    bool is_even = (num & 1) == 0;
    bool is_greater_than_7 = num > 7;
    return is_even && is_greater_than_7;
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

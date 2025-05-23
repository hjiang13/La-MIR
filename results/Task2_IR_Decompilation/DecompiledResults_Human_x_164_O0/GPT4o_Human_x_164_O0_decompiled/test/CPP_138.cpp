#include <stdbool.h>

bool is_equal_to_sum_even(int x) {
    bool result;
    if (x % 2 == 0) {
        if (x >= 8) {
            result = true;
        } else {
            result = false;
        }
    } else {
        result = false;
    }
    return result;
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

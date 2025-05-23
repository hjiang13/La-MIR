```c++
#include <stdbool.h>

bool iscuber(int input) {
    int abs_input = __builtin_abs(input);
    int result = 0;

    while (true) {
        int temp1 = result * result;
        int temp2 = temp1 * result;
        bool condition = temp2 < abs_input;

        if (condition) {
            result++;
        } else {
            bool final_condition = temp2 <= abs_input;
            return final_condition;
        }
    }
}


#undef NDEBUG
#include<assert.h>
int main(){
    assert (iscuber(1) == true);
    assert (iscuber(2) == false);
    assert (iscuber(-1) == true);
    assert (iscuber(64) == true);
    assert (iscuber(180) == false);
    assert (iscuber(1000) == true);
    assert (iscuber(0) == true);
    assert (iscuber(1729) == false);
}

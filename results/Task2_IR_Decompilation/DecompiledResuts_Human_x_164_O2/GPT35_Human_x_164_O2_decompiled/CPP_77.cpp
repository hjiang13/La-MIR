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

```
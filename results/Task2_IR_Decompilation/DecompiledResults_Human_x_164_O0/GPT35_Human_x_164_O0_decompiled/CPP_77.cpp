```c
#include <stdbool.h>

int abs(int);

bool iscuber(int num) {
    int result = 0;
    int counter = 0;

    do {
        int temp = result * counter;
        temp = temp * counter;
        int abs_num = abs(num);

        if (temp <= abs_num) {
            int temp2 = result * counter;
            temp2 = temp2 * counter;
            int abs_num2 = abs(num);

            if (temp2 == abs_num2) {
                return true;
            }
        }

        counter++;
    } while (true);

    return false;
}
```
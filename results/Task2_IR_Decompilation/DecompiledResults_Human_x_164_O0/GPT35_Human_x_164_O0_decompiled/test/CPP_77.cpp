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

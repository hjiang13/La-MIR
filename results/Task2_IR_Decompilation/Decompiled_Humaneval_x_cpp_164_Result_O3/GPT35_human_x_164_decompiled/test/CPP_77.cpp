```c
#include <stdbool.h>

bool iscuber(int x) {
    int abs_x = __builtin_abs(x);
    int result = 0;

    do {
        int x_squared = result * result;
        int x_cubed = x_squared * result;
        
        if (x_cubed < abs_x) {
            result++;
        } else {
            break;
        }
    } while (true);

    return x_cubed <= abs_x;
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

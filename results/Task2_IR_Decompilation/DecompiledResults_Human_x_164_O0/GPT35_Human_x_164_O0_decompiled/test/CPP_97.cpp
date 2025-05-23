```c
#include <stdlib.h>

int abs(int x);

int multiply(int a, int b) {
    int x = a;
    int y = b;
    x = abs(x);
    int mod_x = x % 10;
    y = abs(y);
    int mod_y = y % 10;
    return mod_x * mod_y;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (multiply(148, 412) == 16                   );
    assert (multiply(19, 28) == 72       );
    assert (multiply(2020, 1851) == 0);
    assert (multiply(14,-15) == 20   );
    assert (multiply(76, 67) == 42    );
    assert (multiply(17, 27) == 49    );
    assert (multiply(0, 1) == 0);
    assert (multiply(0, 0) == 0);
}

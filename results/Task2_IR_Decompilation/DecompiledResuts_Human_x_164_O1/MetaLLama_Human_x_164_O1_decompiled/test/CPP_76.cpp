#include <stdio.h>
#include <stdbool.h>

bool is_simple_power(int a, int b) {
    if (a > 0) {
        if (a > 1) {
            int i = 0;
            int x = 1;
            do {
                x *= b;
                i++;
                if (x <= a && i < 99) {
                    continue;
                } else {
                    return x == a;
                }
            } while (x != a);
        }
        return true;
    }
    return false;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_simple_power(1, 4)== true);
    assert (is_simple_power(2, 2)==true);
    assert (is_simple_power(8, 2)==true);
    assert (is_simple_power(3, 2)==false);
    assert (is_simple_power(3, 1)==false);
    assert (is_simple_power(5, 3)==false);
    assert (is_simple_power(16, 2)== true);
    assert (is_simple_power(143214, 16)== false);
    assert (is_simple_power(4, 2)==true);
    assert (is_simple_power(9, 3)==true);
    assert (is_simple_power(16, 4)==true);
    assert (is_simple_power(24, 2)==false);
    assert (is_simple_power(128, 4)==false);
    assert (is_simple_power(12, 6)==false);
    assert (is_simple_power(1, 1)==true);
    assert (is_simple_power(1, 12)==true);
}

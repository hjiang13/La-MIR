#include <iostream>

extern "C" int starts_one_endsi(int arg) {
    int result;
    if (arg < 1) {
        result = 0;
    } else if (arg == 1) {
        result = 1;
    } else {
        int multiplier = 18;
        int count = 2;
        while (count < arg) {
            multiplier *= 10;
            count++;
        }
        result = multiplier;
    }
    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (starts_one_ends(1) == 1);
    assert (starts_one_ends(2) == 18);
    assert (starts_one_ends(3) == 180);
    assert (starts_one_ends(4) == 1800);
    assert (starts_one_ends(5) == 18000);
}

#include <iostream>
#include <string>

using namespace std;

bool any_int(float a, float b, float c) {
    int round_a = round(a);
    int round_b = round(b);
    int round_c = round(c);

    if (round_a == round_b && round_b == round_c) {
        return true;
    }

    if (round_a == round_b && round_b != round_c) {
        return false;
    }

    if (round_a != round_b && round_b == round_c) {
        return false;
    }

    if (round_a != round_b && round_b != round_c) {
        return true;
    }

    return false;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (any_int(2, 3, 1)==true);
    assert (any_int(2.5, 2, 3)==false);
    assert (any_int(1.5, 5, 3.5)==false);
    assert (any_int(2, 6, 2)==false);
    assert (any_int(4, 2, 2)==true);
    assert (any_int(2.2, 2.2, 2.2)==false);
    assert (any_int(-4, 6, 2)==true);
    assert (any_int(2,1,1)==true);
    assert (any_int(3,4,7)==true);
    assert (any_int(3.01,4,7)==false);
}

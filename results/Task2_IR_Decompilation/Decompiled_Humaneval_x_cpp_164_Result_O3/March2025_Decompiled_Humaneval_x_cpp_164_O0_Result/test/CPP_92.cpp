#include <cmath>

extern "C" bool any_int(float a, float b, float c) {
    if (std::round(a) != a) {
        return false;
    }
    if (std::round(b) != b) {
        return false;
    }
    if (std::round(c) != c) {
        return false;
    }
    if (a + b == c || a + c == b || b + c == a) {
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

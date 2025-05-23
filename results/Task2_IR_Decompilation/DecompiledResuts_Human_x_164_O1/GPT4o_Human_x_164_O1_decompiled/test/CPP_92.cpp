#include <cmath>

extern "C" bool any_int(float a, float b, float c) {
    float ra = roundf(a);
    bool cond1 = ra != a;
    float rb = roundf(b);
    bool cond2 = rb != b;
    bool any_rounded = cond1 || cond2;

    float rc = roundf(c);
    bool cond3 = rc != c;
    any_rounded = any_rounded || cond3;

    if (any_rounded) {
        return true;
    } else {
        float sum1 = a + b;
        bool cond4 = sum1 == c;
        float sum2 = a + c;
        bool cond5 = sum2 == b;
        bool any_sum = cond4 || cond5;

        float sum3 = b + c;
        bool cond6 = sum3 == a;
        return any_sum || cond6;
    }
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

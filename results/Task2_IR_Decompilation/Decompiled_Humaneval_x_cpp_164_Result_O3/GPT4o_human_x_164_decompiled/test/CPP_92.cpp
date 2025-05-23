#include <cmath>

extern "C" bool any_int(float a, float b, float c) {
    float rounded_a = roundf(a);
    bool condition_a = rounded_a != a;
    float rounded_b = roundf(b);
    bool condition_b = rounded_b != b;
    bool any_condition = condition_a || condition_b;
    float rounded_c = roundf(c);
    bool condition_c = rounded_c != c;
    bool final_condition = any_condition || condition_c;

    if (!final_condition) {
        return false;
    }

    float sum_ab = a + b;
    bool eq_ab_c = sum_ab == c;
    float sum_ac = a + c;
    bool eq_ac_b = sum_ac == b;
    bool result = eq_ab_c || eq_ac_b;
    float sum_bc = b + c;
    bool eq_bc_a = sum_bc == a;

    return result || eq_bc_a;
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

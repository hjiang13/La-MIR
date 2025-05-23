#include <cmath>

bool any_intfff(float a, float b, float c) {
    bool result = true;

    float roundedA = roundf(a);
    if (roundedA != a) {
        result = false;
    } else {
        float roundedB = roundf(b);
        if (roundedB != b) {
            result = false;
        } else {
            float roundedC = roundf(c);
            if (roundedC != c) {
                result = false;
            } else {
                if ((a + b) == c) {
                    result = true;
                } else {
                    if ((a + c) == b) {
                        result = true;
                    } else {
                        if ((b + c) == a) {
                            result = true;
                        } else {
                            result = false;
                        }
                    }
                }
            }
        }
    }
    return result;
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

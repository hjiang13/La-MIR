#include <cstdint>

extern "C" int32_t mod(int32_t a, int32_t b) {
    if (a <= 0) {
        return 1;
    }
    
    int32_t result = 1;
    int32_t temp = a;
    
    while (true) {
        if ((temp & 3) == 0) {
            break;
        }
        temp &= -4; // equivalent to temp = temp & ~3
    }

    while (true) {
        int32_t shift = result << 1;
        int32_t remainder = shift % b;
        result = (temp == 0) ? remainder : (result << 1) % b;

        temp -= 4;
        if (temp == 0) {
            break;
        }
    }

    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (modp(3, 5) == 3);
    assert (modp(1101, 101) == 2);
    assert (modp(0, 101) == 1);
    assert (modp(3, 11) == 8);
    assert (modp(100, 101) == 1);
    assert (modp(30, 5) == 4);
    assert (modp(31, 5) == 3);
}

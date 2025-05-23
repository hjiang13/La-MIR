#include <cstdint>

extern "C" int32_t mod(int32_t a, int32_t b) {
    int32_t result = 1;
    int32_t i = 0;

    while (i < a) {
        result = (result * 2) % b;
        i++;
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

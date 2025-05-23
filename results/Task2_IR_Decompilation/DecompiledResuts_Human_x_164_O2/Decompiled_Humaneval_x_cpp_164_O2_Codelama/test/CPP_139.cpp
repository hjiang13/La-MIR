#include <cstdint>

uint64_t special_factorial(uint32_t n) {
    if (n < 1) {
        return 1;
    }
    uint64_t result = n;
    while (n > 1) {
        n--;
        result *= n;
    }
    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (special_factorial(4) == 288);
    assert (special_factorial(5) == 34560);
    assert (special_factorial(7) == 125411328000);
    assert (special_factorial(1) == 1);
}

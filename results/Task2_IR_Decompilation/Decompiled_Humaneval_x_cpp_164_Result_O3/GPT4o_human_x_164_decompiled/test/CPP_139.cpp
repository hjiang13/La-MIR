#include <cstdint>

extern "C" int64_t special_factorial(int32_t n) {
    if (n < 1) {
        return 1;
    } else {
        int64_t result = 1;
        for (int32_t i = 1; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (special_factorial(4) == 288);
    assert (special_factorial(5) == 34560);
    assert (special_factorial(7) == 125411328000);
    assert (special_factorial(1) == 1);
}

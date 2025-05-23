#include <cstdint>

int64_t special_factorial(int32_t n) {
    int32_t i = 1;
    int64_t result = 1;
    int64_t temp = 1;

    while (i <= n) {
        result *= i;
        temp *= result;
        ++i;
    }

    return temp;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (special_factorial(4) == 288);
    assert (special_factorial(5) == 34560);
    assert (special_factorial(7) == 125411328000);
    assert (special_factorial(1) == 1);
}

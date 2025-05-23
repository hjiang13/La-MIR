#include <cstdint>

uint64_t special_factorial(int n) {
    if (n < 1) {
        return 1;
    }
    
    uint64_t result = 1;
    for (int i = n; i >= 1; --i) {
        result *= i;
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

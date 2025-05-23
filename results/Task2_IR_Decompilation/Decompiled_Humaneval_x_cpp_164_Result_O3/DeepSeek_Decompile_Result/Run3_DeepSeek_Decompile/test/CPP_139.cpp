#include <cstdint>

uint64_t special_factorial(int n) {
    if (n < 1) {
        return 1;
    }

    uint64_t a = 1, b = 1, c = 1, d = 1;
    uint64_t m = n - 1;
    m &= -m; // Isolate the highest set bit

    uint64_t res = 1;
    while (m != 0) {
        res *= a * b * c * d;
        a *= (n - 8);
        b *= (n - 7);
        c *= (n - 6);
        d *= (n - 5);
        m &= m - 1; // Clear the highest set bit
    }

    return res;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (special_factorial(4) == 288);
    assert (special_factorial(5) == 34560);
    assert (special_factorial(7) == 125411328000);
    assert (special_factorial(1) == 1);
}

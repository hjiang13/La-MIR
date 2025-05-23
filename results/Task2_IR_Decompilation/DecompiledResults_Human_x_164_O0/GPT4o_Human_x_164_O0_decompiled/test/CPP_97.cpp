#include <cstdlib>

extern "C" int abs(int x) {
    return (x < 0) ? -x : x;
}

extern "C" int multiply(int a, int b) {
    int abs_a = abs(a);
    int abs_b = abs(b);
    return (abs_a % 10) * (abs_b % 10);
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (multiply(148, 412) == 16                   );
    assert (multiply(19, 28) == 72       );
    assert (multiply(2020, 1851) == 0);
    assert (multiply(14,-15) == 20   );
    assert (multiply(76, 67) == 42    );
    assert (multiply(17, 27) == 49    );
    assert (multiply(0, 1) == 0);
    assert (multiply(0, 0) == 0);
}

#include <cstdlib>

int multiply(int a, int b) {
    int abs_a = std::abs(a);
    int abs_b = std::abs(b);
    int mod_a = abs_a % 10;
    int mod_b = abs_b % 10;
    return mod_a * mod_b;
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

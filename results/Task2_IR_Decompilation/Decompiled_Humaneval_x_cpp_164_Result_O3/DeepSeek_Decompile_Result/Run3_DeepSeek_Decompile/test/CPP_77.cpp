#include <cstdlib> // For abs()

bool iscuber(int x) {
    int abs_x = std::abs(x);
    int n = 0;
    while (true) {
        int cube = n * n * n;
        if (cube > abs_x) {
            break;
        }
        ++n;
    }
    return (n * n * n) <= abs_x;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (iscuber(1) == true);
    assert (iscuber(2) == false);
    assert (iscuber(-1) == true);
    assert (iscuber(64) == true);
    assert (iscuber(180) == false);
    assert (iscuber(1000) == true);
    assert (iscuber(0) == true);
    assert (iscuber(1729) == false);
}

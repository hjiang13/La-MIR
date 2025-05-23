#include <cstdlib> // for abs

bool iscuberi(int x) {
    int x_abs = std::abs(x);
    int i = 0;
    while (true) {
        int cube = i * i * i;
        if (cube == x_abs) {
            return true;
        }
        if (cube > x_abs) {
            return false;
        }
        ++i;
    }
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

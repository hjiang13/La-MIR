#include <cmath>

bool iscuber(int n) {
    int i = 0;
    while (true) {
        int cube = i * i * i;
        if (cube == std::abs(n)) {
            return true;
        }
        if (cube > std::abs(n)) {
            return false;
        }
        i++;
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

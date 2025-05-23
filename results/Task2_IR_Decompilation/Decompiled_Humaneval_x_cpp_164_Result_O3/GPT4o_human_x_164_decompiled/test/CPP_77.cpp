#include <cmath>

bool iscuberi(int x) {
    int abs_x = std::abs(x);
    int y = 0;

    while (true) {
        int cube = y * y * y;
        if (cube >= abs_x) {
            break;
        }
        y++;
    }

    return (y * y * y) <= abs_x;
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

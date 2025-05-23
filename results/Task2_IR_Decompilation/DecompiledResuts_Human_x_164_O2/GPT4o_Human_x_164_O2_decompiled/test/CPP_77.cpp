#include <cmath>

extern "C" int abs(int x) {
    return (x < 0) ? -x : x;
}

extern "C" bool iscube(int n) {
    int abs_n = abs(n);
    int x = 0;
    while (true) {
        int cube = x * x * x;
        if (cube >= abs_n) {
            break;
        }
        x++;
    }
    return (x * x * x) == abs_n;
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

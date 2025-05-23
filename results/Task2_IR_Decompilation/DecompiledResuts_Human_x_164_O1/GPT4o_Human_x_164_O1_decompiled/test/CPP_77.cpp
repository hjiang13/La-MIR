#include <cmath>

extern "C" {
    int abs(int x) {
        return (x < 0) ? -x : x;
    }
}

bool iscuberi(int n) {
    int cube = abs(n);
    int x = 0;

    while (true) {
        int y = x * x * x;
        if (y >= cube) {
            return y == cube;
        }
        x++;
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

#include <stdio.h>

int iscuber(int x) {
    int abs_x = (x < 0) ? -x : x;
    int i = 0;
    while (1) {
        long long cube = (long long)i * i * i;
        if (cube >= abs_x) break;
        i++;
    }
    return cube <= abs_x;
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

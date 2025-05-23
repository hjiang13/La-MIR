#include <stdbool.h>

bool is_cube_root(int n) {
    int i = 0;
    int abs_n = n < 0 ? -n : n;
    while (i * i * i < abs_n) {
        i++;
    }
    return i * i * i <= abs_n;
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

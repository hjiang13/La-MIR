#include <stdbool.h>

bool iscuberi(int i) {
    int abs_i = (i < 0) ? -i : i;
    int j = 0;
    while (true) {
        int j_cubed = j * j * j;
        if (j_cubed >= abs_i) break;
        j++;
    }
    return j_cubed <= abs_i;
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

#include <stdbool.h>

bool iscuber(int x) {
    int result = x;
    do {
        int square = result * result;
        int cube = square * result;
        if (cube < abs(x)) {
            result++;
        } else {
            return cube <= abs(x);
        }
    } while (true);
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

#include <cstdlib>

extern "C" int abs(int x) {
    return (x < 0) ? -x : x;
}

extern "C" bool iscuberi(int input) {
    bool result = false;
    int temp = 0;
    int counter = 0;

    while (true) {
        int squared = counter * counter;
        int cubed = squared * counter;
        int absInput = abs(input);

        if (cubed <= absInput) {
            int absCounterCubed = abs(cubed);
            if (cubed == absCounterCubed) {
                result = true;
                break;
            }
        } else {
            break;
        }

        counter++;
    }

    return result;
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

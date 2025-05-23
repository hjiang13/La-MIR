int modp(int a, int b) {
    if (a > 0) {
        int c = a - 1;
        int d = a & 3;
        if (c < 3) {
            int x = 1;
            int y = d;
            while (y != 0) {
                x = (x << 1) % b;
                y--;
            }
            return x;
        } else {
            int e = a & -4;
            int x = 1;
            while (e != 0) {
                x = (((((x << 1) % b) << 1) % b) << 1) % b;
                e -= 4;
            }
            int y = a & 3;
            while (y != 0) {
                x = (x << 1) % b;
                y--;
            }
            return x;
        }
    } else {
        return 1;
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (modp(3, 5) == 3);
    assert (modp(1101, 101) == 2);
    assert (modp(0, 101) == 1);
    assert (modp(3, 11) == 8);
    assert (modp(100, 101) == 1);
    assert (modp(30, 5) == 4);
    assert (modp(31, 5) == 3);
}

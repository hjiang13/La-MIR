int modp(int a, int b) {
    if (a > 0) {
        if ((a & 3) == 0) {
            a = 1;
        } else {
            int c = a - 1;
            int d = a & 3;
            int e = 1;
            do {
                e = (e << 1) % b;
                d--;
            } while (d != 0);
            a = e;
        }
    } else {
        a = 1;
    }
    return a;
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

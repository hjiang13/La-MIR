int modp(int a, int b) {
    if (a > 0) {
        int tmp = a - 1;
        int and = a & 3;
        if (tmp < 3)
            goto label10;
        else {
            int tmp2 = a & -4;
            while (1) {
                int shift = tmp2 << 1;
                int rem = shift % b;
                shift = rem << 1;
                rem = shift % b;
                shift = rem << 1;
                rem = shift % b;
                shift = rem << 1;
                rem = shift % b;
                tmp2 = tmp2 + (-4);
                if (tmp2 == 0)
                    break;
            }
            return rem;
        }
    }
    return 1;
label10:
    int c = 1;
    int d = and;
    while (1) {
        int shift = c << 1;
        int rem = shift % b;
        c = rem;
        d = d - 1;
        if (d == 0)
            break;
    }
    return rem;
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

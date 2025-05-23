#include <iostream>

long long special_factorial(int n) {
    if (n < 1) {
        return 1;
    }

    int m = n + 1;
    long long a = m - 1;
    long long b = a - 2;
    long long c = a & 7;

    if (b < 7) {
        // Handle small values
    } else {
        long long d = c & (-8);
        long long e, f, g, h;
        e = f = g = h = 1;

        while (true) {
            long long ee = e * g;
            long long ff = ee * f;
            long long gg = e + 1;
            long long hh = ee * gg;
            long long ii = ee * (gg + 1);
            long long jj = hh * ii;
            long long kk = gg + 2;
            long long ll = hh * kk;
            long long mm = ll * jj;
            long long nn = gg + 3;
            long long oo = ll * nn;
            long long pp = oo * mm;
            long long qq = gg + 4;
            long long rr = oo * qq;
            long long ss = rr * pp;
            long long tt = gg + 5;
            long long uu = rr * tt;
            long long vv = uu * ss;
            long long ww = gg + 6;
            long long xx = uu * ww;
            long long yy = xx * vv;
            long long zz = gg + 7;
            long long aaa = xx * zz;
            long long bbb = aaa * yy;
            g += 8;
            d -= 8;

            if (d == 0) {
                break;
            }
        }
    }

    return 1;
}

int main() {
    std::cout << special_factorial(10) << std::endl;
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (special_factorial(4) == 288);
    assert (special_factorial(5) == 34560);
    assert (special_factorial(7) == 125411328000);
    assert (special_factorial(1) == 1);
}

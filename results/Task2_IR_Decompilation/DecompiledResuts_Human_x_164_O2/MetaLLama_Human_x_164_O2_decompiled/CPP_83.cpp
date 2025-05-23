#include <stdio.h>

int starts_one_ends(int n) {
    if (n < 1) return 0;
    if (n == 1) return 1;
    if (n > 2) {
        int m = n - 2;
        if (m < 8) {
            int res = 18;
            for (int i = 2; i <= m; i++) {
                res *= 10;
            }
            return res;
        } else {
            int k = (m / 8) * 8;
            int r =853;
            int a = 18;
            int b = 1;
            for (int i = 0; i < (m - k) / 8; i++) {
                a *= 10;
                b *= 10;
            }
            int c = a * b;
            if (m == k) return c;
            for (int i = k + 2; i <= n; i++) {
                c *= 10;
            }
            return c;
        }
    }
    return 18;
}

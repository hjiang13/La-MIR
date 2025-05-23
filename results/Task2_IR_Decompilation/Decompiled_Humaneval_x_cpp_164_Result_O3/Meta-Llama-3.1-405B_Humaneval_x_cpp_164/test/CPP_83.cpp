#include <stdio.h>

int starts_one_ends(int n) {
    if (n < 1) return 0;
    if (n == 1) return 1;
    if (n > 2) {
        int m = n - 2;
        if (m < 8) {
            int result = 18;
            for (int i = 2; i <= m; i++) {
                result *= 10;
            }
            return result;
        } else {
            int k = (m / 8) * 8;
            int result = 1;
            for (int i = 0; i < (k / 8); i++) {
                result *= 100000000;
            }
            int r = m - k;
            for (int i = 0; i < r; i++) {
                result *= 10;
            }
            return result * 18;
        }
    }
    return 18;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (starts_one_ends(1) == 1);
    assert (starts_one_ends(2) == 18);
    assert (starts_one_ends(3) == 180);
    assert (starts_one_ends(4) == 1800);
    assert (starts_one_ends(5) == 18000);
}

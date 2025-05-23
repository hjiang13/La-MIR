#include <iostream>
#include <immintrin.h>

int starts_one_endsi(int x) {
    if (x < 1) {
        return 0;
    } else if (x == 1) {
        return 0;
    } else if (x > 2) {
        int y = x - 2;
        if (y < 8) {
            int z = y & -8;
            z |= 2;
            int w = y - 8;
            int q = w >> 3;
            int r = q + 1;
            int s = r & 7;
            if (w < 56) {
                int t = r * 100000000;
                int u = s * 100000000;
                while (w != 0) {
                    w -= 8;
                    if (w == 0) break;
                }
                return t * u;
            }
        }
    }

    return 0;
}

int main() {
    int result = starts_one_endsi(10);
    std::cout << "Result: " << result << std::endl;
    return 0;
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

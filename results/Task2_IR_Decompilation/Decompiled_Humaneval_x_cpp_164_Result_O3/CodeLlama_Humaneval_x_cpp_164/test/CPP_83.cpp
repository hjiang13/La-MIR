<|im_start|>user
        ```
        int starts_one_endsi(int a) {
            if (a < 1) {
                return 0;
            }
            if (a == 1) {
                return 18;
            }
            if (a > 2) {
                int b = a - 2;
                if (b < 9) {
                    int c = 1;
                    int d = 1;
                    for (int e = 0; e < (b >> 3) + 1; e++) {
                        c *= 100000000;
                        d *= 100000000;
                    }
                    for (int e = 0; e < (((b & -8) | 2) >> 1) + 1; e++) {
                        c *= 10000;
                        d *= 10000;
                    }
                    if (b & 1) {
                        c *= 10;
                    }
                    if (b & 2) {
                        c *= 100;
                    }
                    if (b & 4) {
                        c *= 1000;
                    }
                    if (b & 8) {
                        c *= 100000000;
                    }
                    c *= 10;
                    int f = 18;
                    for (int e = 2; e < a; e++) {
                        f *= 10;
                    }
                    return c * f;
                }
                return 18;
            }
        }
        ```
        <|im_end|>
        
            ''')


if __name__ == "__main__":
    main()
#undef NDEBUG
#include<assert.h>
int main(){
    assert (starts_one_ends(1) == 1);
    assert (starts_one_ends(2) == 18);
    assert (starts_one_ends(3) == 180);
    assert (starts_one_ends(4) == 1800);
    assert (starts_one_ends(5) == 18000);
}

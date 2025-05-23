#include <stdio.h>

int fizz_buzz(int n) {
    int count = 0;
int i = 0;
int fizz = 0;
int buzz = 0;

    if (n <= 0) {
        return 0;
    }

    while (1) {
        i = 0;
        fizz = 0;
        buzz = 0;
        while (i <= n) {
            if (i % 11 == 0 || i % 13 == 0) {
                if (i % 10 == 7) {
                    fizz++;
                }
                i /= 10;
                if (i > 9) {
                    continue;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        count = fizz;
        i++;
        if (i == n) {
            break;
        }
    }

    return count;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (fizz_buzz(50) == 0);
    assert (fizz_buzz(78) == 2);
    assert (fizz_buzz(79) == 3);
    assert (fizz_buzz(100) == 3);
    assert (fizz_buzz(200) == 6);
    assert (fizz_buzz(4000) == 192);
    assert (fizz_buzz(10000) == 639);
    assert (fizz_buzz(100000) == 8026);
}

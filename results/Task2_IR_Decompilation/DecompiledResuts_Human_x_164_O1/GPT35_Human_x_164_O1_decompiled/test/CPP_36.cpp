#include <stdio.h>

int fizz_buzzi(int num) {
    if (num > 0) {
        int res = 0;
        while (1) {
            if ((num % 11 == 0) || (num % 13 == 0) || (num % 10 == 7)) {
                res += num / 10;
            }
            if (num > 9) {
                num = num / 10;
            } else {
                break;
            }
        }
        return res;
    } else {
        return 0;
    }
}

int main() {
    int num = 12345; // Input number
    int result = fizz_buzzi(num);
    printf("Result: %d\n", result);
    return 0;
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

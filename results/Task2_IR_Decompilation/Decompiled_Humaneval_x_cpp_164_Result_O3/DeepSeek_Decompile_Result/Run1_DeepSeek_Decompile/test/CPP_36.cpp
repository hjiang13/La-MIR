int fizz_buzz(int n) {
    if (n <= 0)
        return 0;
    int sum = 0;
    for (int current = 1; current <= n; ++current) {
        bool mod11 = (current % 11 == 0);
        bool mod13 = (current % 13 == 0);
        if (mod11 || mod13) {
            int num = current;
            do {
                if (num % 10 == 7) {
                    sum++;
                }
                num /= 10;
            } while (num != 0);
        }
    }
    return sum;
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

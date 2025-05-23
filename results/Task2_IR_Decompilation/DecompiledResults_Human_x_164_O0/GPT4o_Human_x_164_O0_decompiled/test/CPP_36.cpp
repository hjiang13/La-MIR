#include <iostream>

int fizz_buzz(int n) {
    int count = 0;
    int current = 0;

    while (current < n) {
        if (current % 11 == 0 || current % 13 == 0) {
            if (current > 0 && current % 10 == 7) {
                count++;
            }
            current /= 10;
        }
        current++;
    }

    return count;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << fizz_buzz(n) << std::endl;
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

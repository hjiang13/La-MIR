#include <iostream>

int mod(int a, int b) {
    if (a > 0) {
        int res = 1;
        for (int i = 1; i < a; i++) {
            res = (res * 2) % b;
        }
        return res;
    }
    return 1;
}

int main() {
    int a = 5;
    int b = 3;
    int result = mod(a, b);
    std::cout << "Result: " << result << std::endl;
    return 0;
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

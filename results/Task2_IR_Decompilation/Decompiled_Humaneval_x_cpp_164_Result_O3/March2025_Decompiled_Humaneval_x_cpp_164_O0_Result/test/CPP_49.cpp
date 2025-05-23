#include <iostream>

int modp(int a, int b) {
    int result = 1;
    int counter = 0;
    while (counter < a) {
        result = (result * 2) % b;
        counter++;
    }
    return result;
}

int main() {
    int a = 5; // Example input
    int b = 3; // Example input
    std::cout << modp(a, b) << std::endl;
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

#include <iostream>

int mod(int a, int b) {
    if (a <= 0) {
        return 1;
    }
    
    int temp = a & 3;
    if ((a - 1) < 3) {
        return (a & -4);
    }
    
    int result = 1;
    int count = 1;
    
    while (true) {
        if (temp == 0) {
            return result;
        }
        
        result = (result << 1) % b;
        temp--;
        
        if (temp == 0) {
            return result;
        }
    }
}

int main() {
    int a = 10; // Example input
    int b = 3;  // Example input
    std::cout << mod(a, b) << std::endl;
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

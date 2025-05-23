#include <iostream>

using namespace std;

int mod_pi(int a, int m) {
    int result = 1;
    a = abs(a);
    
    // If m is a power of two, use bitwise operations
    if ((m & (m - 1)) == 0) {
        result = a & (m - 1);
    } else {
        // Otherwise, use a loop to compute the modulo
        while (a >= m) {
            a -= m;
            result = a;
        }
    }
    
    return result;
}

int main() {
    // Example usage
    int a = 10, m = 3;
    cout << "Modulo result: " << mod_pi(a, m) << endl;
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

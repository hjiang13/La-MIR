#include <stdio.h>
#include <string>
using namespace std;

int mod(int a, int b) {
    if (a > 0) {
        int r = a % b;
        if (r == 0) {
            return 1;
        } else {
            return r;
        }
    } else {
        return 0;
    }
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

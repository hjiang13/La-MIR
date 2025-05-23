#include <iostream>

using namespace std;

int starts_one_ends(int x) {
    if (x < 1) {
        return 0;
    } else if (x == 1) {
        return 1;
    } else if (x <= 2) {
        return 0;
    }

    int value = x - 2;
    int result = 18;

    if (value >= 8) {
        int tmp = value & (-8);
        tmp |= 2;
        value += tmp;
        value = (value >> 3) + 1;
        value &= 7;

        while (value != 0) {
            result *= 10;
            value--;
        }
    }

    while (true) {
        result *= 10;
        x--;
        if (x == value) {
            break;
        }
    }

    return result;
}

int main() {
    // Example usage:
    cout << starts_one_ends(3) << endl;  // Output: 18
    cout << starts_one_ends(9) << endl;   // Output: 180000000
    cout << starts_one_ends(10) << endl;  // Output: 1800000000
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (starts_one_ends(1) == 1);
    assert (starts_one_ends(2) == 18);
    assert (starts_one_ends(3) == 180);
    assert (starts_one_ends(4) == 1800);
    assert (starts_one_ends(5) == 18000);
}

#include <iostream>

using namespace std;

int starts_one_ends(int x) {
    if (x < 1) {
        return 0;
    } else if (x == 1) {
        return 1;
    } else if (x <= 2) {
        return 18;
    }

    int a = x - 2;
    if (a < 8) {
        int b = 2;
        int c = 18;
        while (true) {
            c *= 10;
            b++;
            if (b == x) {
                return c;
            }
        }
    }

    int d = a & (-8);
    int e = d | 2;
    int f = d - 8;
    int g = (f >> 3) + 1;
    int h = g & 7;

    if (f < 56) {
        int i = 0;
        while (true) {
            i++;
            if (i > h) {
                break;
            }
        }
    } else {
        int i = 1073741816 & g;
        while (true) {
            i -= 8;
            if (i == 0) {
                break;
            }
        }
    }

    int j = 18;
    if (h == 0) {
        return j;
    }

    while (true) {
        j *= 10;
        h--;
        if (h == 0) {
            break;
        }
    }

    if (a == d) {
        return j;
    }

    int k = 2;
    int l = j;
    while (true) {
        l *= 10;
        k++;
        if (k == x) {
            return l;
        }
    }
}

int main() {
    // Example usage:
    cout << starts_one_ends(3) << endl;  // Output should be 18
    cout << starts_one_ends(9) << endl;   // Output should be 1800000000
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

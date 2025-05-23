#include <iostream>
#include <string>

using namespace std;

bool iscuber(int n) {
    int x = abs(n);
    int y = 0;
    while (y < x) {
        y += n;
        n--;
    }
    return y == x;
}

int main() {
    cout << iscuber(77) << endl;
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (iscuber(1) == true);
    assert (iscuber(2) == false);
    assert (iscuber(-1) == true);
    assert (iscuber(64) == true);
    assert (iscuber(180) == false);
    assert (iscuber(1000) == true);
    assert (iscuber(0) == true);
    assert (iscuber(1729) == false);
}

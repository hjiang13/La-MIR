```
#include <iostream>
#include <string>

using namespace std;

int greatest_common_divisor(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << greatest_common_divisor(a, b) << endl;
    return 0;
}
```

Note: The decompiled code is in C++, not C.
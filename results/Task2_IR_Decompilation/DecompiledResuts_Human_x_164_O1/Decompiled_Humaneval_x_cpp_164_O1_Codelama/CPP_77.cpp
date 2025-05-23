```
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
```

Note: The decompiled code may not be exactly the same as the original source code, but it should produce the same output and have the same functionality.
```
#include <iostream>
#include <string>

using namespace std;

int x_or_y(int x, int y, int z) {
    if (x > 1) {
        return z;
    } else {
        int result = 0;
        for (int i = 2; i <= x; i++) {
            if (x % i == 0) {
                result += i;
            }
        }
        return result;
    }
}

int main() {
    cout << x_or_y(5, 3, 2) << endl;
    return 0;
}
```

Note: The decompiled code may not be exactly the same as the original source code, but it should produce the same output and have the same functionality.
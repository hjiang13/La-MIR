```
#include <iostream>
#include <string>

using namespace std;

int multiply(int a, int b) {
    int result = 0;
    while (a > 0) {
        result += b;
        a--;
    }
    return result;
}

int main() {
    cout << multiply(5, 3) << endl;
    return 0;
}
```

Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should still accurately represent the program logic and behavior of the original source code.
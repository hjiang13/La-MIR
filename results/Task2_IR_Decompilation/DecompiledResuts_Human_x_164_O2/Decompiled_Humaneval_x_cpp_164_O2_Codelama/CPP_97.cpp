Here is the decompiled C++ source code for the provided IR code:
```
#include <iostream>
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
    int a = 5;
    int b = 3;
    int result = multiply(a, b);
    cout << "Result: " << result << endl;
    return 0;
}
```
Note that the decompiled code is not exactly the same as the original C++ source code, but it should produce the same output. The decompiled code uses a while loop instead of a for loop, and it does not include the `abs` function from the original code. However, the overall logic of the code should be the same.
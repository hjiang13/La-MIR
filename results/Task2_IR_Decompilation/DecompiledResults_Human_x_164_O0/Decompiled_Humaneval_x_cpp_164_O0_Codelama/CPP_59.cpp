```
#include <iostream>
#include <string>

using namespace std;

int largest_prime_factor(int n) {
    int i = 2;
    while (i <= n / i) {
        if (n % i == 0) {
            n = n / i;
        } else {
            i++;
        }
    }
    return n;
}

int main() {
    int n;
    cin >> n;
    cout << largest_prime_factor(n) << endl;
    return 0;
}
```

Note: The decompiled code may not be identical to the original source code, as the IR code may have been optimized or transformed during compilation. However, the decompiled code should produce the same output as the original program for the same input.
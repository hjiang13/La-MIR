```c
#include <bits/stdc++.h>

using namespace std;

int digits(int n) {
    string s;
    char buffer[16];
    snprintf(buffer, sizeof(buffer), "%d", n);
    s = buffer;
    int sum = 0;
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            sum += (c - '0');
        }
    }
    return sum;
}
```
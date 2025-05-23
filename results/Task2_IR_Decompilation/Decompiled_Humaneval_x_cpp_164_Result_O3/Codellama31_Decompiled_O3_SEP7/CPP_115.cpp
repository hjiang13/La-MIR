Sure, I'll do my best to decompile the provided IR code into equivalent C++ source code. Please note that the decompiled code may not be identical to the original source code, but it should be functionally equivalent.

Here's the decompiled C++ code:
```
#include <iostream>
#include <vector>

using namespace std;

int max_fill(vector<vector<int>>& vec, int n) {
    int max_fill = 0;
    for (int i = 0; i < n; i++) {
        int fill = 0;
        for (int j = 0; j < n; j++) {
            fill += vec[i][j];
        }
        max_fill = max(max_fill, fill);
    }
    return max_fill;
}

int main() {
    vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = 3;
    cout << max_fill(vec, n) << endl;
    return 0;
}
```
I hope this helps! Let me know if you have any questions or if you'd like me to explain the decompilation process in more detail.
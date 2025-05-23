Here is the decompiled C++ code for the provided IR code:
```
#include <iostream>
#include <vector>

using namespace std;

float max_element(vector<float> &v) {
    if (v.empty()) {
        return -1.0f;
    }
    float max = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original source code.
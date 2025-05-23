Here is the decompiled C++ source code for the provided IR code:
```
#include <iostream>
#include <vector>

using namespace std;

int solutions(vector<int> &nums) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % 2 == 1) {
            count++;
        }
    }
    return count;
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original source code.
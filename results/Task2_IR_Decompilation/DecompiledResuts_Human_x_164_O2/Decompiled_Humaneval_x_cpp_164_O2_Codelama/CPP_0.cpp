The provided IR code is a function that takes a vector of floats and a float as input, and returns a boolean value. The function checks if the elements in the vector are close to each other, with a maximum difference of 1.

Here is the decompiled C++ code:
```
#include <vector>
#include <cmath>

bool has_close_elements(std::vector<float> vec, float max_diff) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = i + 1; j < vec.size(); j++) {
            if (std::abs(vec[i] - vec[j]) <= max_diff) {
                return true;
            }
        }
    }
    return false;
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original source code.
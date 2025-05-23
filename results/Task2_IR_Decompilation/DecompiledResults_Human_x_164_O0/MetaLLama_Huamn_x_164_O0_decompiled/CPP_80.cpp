Based on the provided LLVM IR code, I will generate the corresponding C source code. Here it is:

```c
#include <string.h>

bool is_happy(const std::string& str) {
    if (str.length() < 3) {
        return false;
    }

    for (int i = 2; i < str.length(); i++) {
        if (str[i] == str[i - 1] || str[i] == str[i - 2]) {
            return false;
        }
    }

    return true;
}
```

Please note that this C source code is a direct translation of the provided LLVM IR code and does not include any additional error checking or handling that may be present in the original C++ code.
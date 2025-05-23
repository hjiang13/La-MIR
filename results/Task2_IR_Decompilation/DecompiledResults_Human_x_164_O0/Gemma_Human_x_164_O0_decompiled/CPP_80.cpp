Based on the provided LLVM IR code, I will generate the corresponding C source code. Here it is:

```c
#include <string.h>

bool is_happy(const std::string& s) {
    if (s.length() < 3) {
        return false;
    }

    int i = 2;
    while (i < s.length()) {
        if (s[i] == s[i - 1] || s[i] == s[i - 2]) {
            return false;
        }
        i++;
    }

    return true;
}
```

Note that I've assumed the `std::string` class is available, as it is used in the IR code. If you want a C-only version without `std::string`, please let me know and I can modify the code accordingly.
```cpp
#include <string>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>

std::string rounded_avg(int a, int b) {
    std::string result;
    if (a > b) {
        result = std::string(2, ' ') + "12589";
    } else {
        int total = a + b;
        if (total > 1) {
            int avg = total / 2;
            char buffer[16];
            int length = vsnprintf(buffer, sizeof(buffer), "%d", avg);
            if (length > 0 && length < sizeof(buffer)) {
                result.append(buffer, length);
            }
        }
    }
    return result;
}
```
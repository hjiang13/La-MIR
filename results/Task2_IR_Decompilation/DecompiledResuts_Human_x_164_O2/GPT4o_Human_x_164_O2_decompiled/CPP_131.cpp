```cpp
#include <cstdarg>
#include <cstdio>
#include <string>

int digitsi(int num) {
    std::string result;
    char buffer[3];
    int length = snprintf(buffer, sizeof(buffer), "%d", num);

    if (length == 0) {
        return 1;
    }

    for (int i = 0; i < length; ++i) {
        if (buffer[i] % 2 == 1) {
            result += (buffer[i] - '0') + 1;
        } else {
            result += (buffer[i] - '0');
        }
    }

    return result.empty() ? 0 : result.length();
}
```
```cpp
#include <string>
#include <cstdlib>

int fruit_distribution(const std::string& input, int num) {
    int len = 0;
    int total = 0;
    int current = 0;

    if (input.empty()) {
        return num;
    }

    const char* str = input.c_str();
    while (str[len] != '\0') {
        len++;
    }

    for (int i = 0; i < len; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            total += strtol(&str[i], nullptr, 10);
            while (str[i] >= '0' && str[i] <= '9') {
                i++;
            }
        }
    }

    current = num - total;
    return current;
}
```
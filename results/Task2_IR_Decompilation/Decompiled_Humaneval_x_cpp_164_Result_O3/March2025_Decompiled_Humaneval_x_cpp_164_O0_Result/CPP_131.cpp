```cpp
#include <string>
#include <stdexcept>

std::string to_string(int value) {
    char buffer[16];
    snprintf(buffer, sizeof(buffer), "%d", value);
    return std::string(buffer);
}

int digits(int input) {
    std::string str = to_string(input);
    int result = 0;
    int multiplier = 1;
    bool found_odd = false;

    for (size_t i = 0; i < str.length(); ++i) {
        char c = str[i];
        if ((c - '0') % 2 == 1) {
            found_odd = true;
            multiplier *= (c - '0');
        }
    }

    if (!found_odd) {
        return 0;
    }

    return multiplier;
}
```
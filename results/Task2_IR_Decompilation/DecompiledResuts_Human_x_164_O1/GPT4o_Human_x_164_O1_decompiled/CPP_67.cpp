```cpp
#include <string>
#include <cstdlib>

int fruit_distribution(std::string input, int size) {
    long long_value1 = 0;
    long long_value2 = 0;
    std::string str1, str2;
    int result = size;

    if (input.size() == 0) {
        return result;
    }

    char* endptr1;
    long_value1 = strtol(input.c_str(), &endptr1, 10);

    char* endptr2;
    long_value2 = strtol(input.c_str(), &endptr2, 10);

    if (endptr1 == input.c_str() || endptr2 == input.c_str()) {
        return result;
    }

    result -= (static_cast<int>(long_value1) + static_cast<int>(long_value2));

    return result;
}
```
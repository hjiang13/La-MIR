```cpp
#include <string>
#include <stdexcept>
#include <cstdlib>

bool valid_date(std::string input) {
    if (input.size() != 10) {
        return false;
    }

    for (size_t i = 0; i < input.size(); ++i) {
        if (i == 2 || i == 5) {
            if (input[i] != '-') return false;
        } else {
            if (input[i] < '0' || input[i] > '9') return false;
        }
    }

    int month = std::strtol(input.substr(5, 2).c_str(), nullptr, 10);
    int day = std::strtol(input.substr(8, 2).c_str(), nullptr, 10);
    int year = std::strtol(input.substr(0, 4).c_str(), nullptr, 10);

    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) return false;
    if (month == 2) {
        bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (leap ? 29 : 28)) return false;
    }

    return true;
}
```
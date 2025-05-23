```cpp
#include <string>
#include <stdexcept>
#include <cstdlib>

bool valid_date(std::string date) {
    if (date.size() != 10) {
        return false;
    }

    char first_digit = date[0] - '0';
    if (first_digit > 9) {
        return false;
    }

    std::string::size_type sz;
    long year = std::strtol(date.substr(0, 4).c_str(), nullptr, 10);
    long month = std::strtol(date.substr(5, 2).c_str(), nullptr, 10);
    long day = std::strtol(date.substr(8, 2).c_str(), nullptr, 10);

    if (month < 1 || month > 12) {
        return false;
    }

    if (day < 1) {
        return false;
    }

    if (month == 2) {
        bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (leap ? 29 : 28)) {
            return false;
        }
    } else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    } else if (day > 31) {
        return false;
    }

    return true;
}
```
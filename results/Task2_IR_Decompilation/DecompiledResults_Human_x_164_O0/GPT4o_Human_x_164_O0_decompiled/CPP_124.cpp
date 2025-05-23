```cpp
#include <string>
#include <cstdlib>

bool valid_date(std::string date) {
    if (date.length() != 10) {
        return false;
    }

    for (int i = 0; i < 10; ++i) {
        if (i == 2) {
            if (date[i] != '-') return false;
        } else {
            if (date[i] < '0' || date[i] > '9') return false;
        }
    }

    int month = std::atoi(date.substr(0, 2).c_str());
    int day = std::atoi(date.substr(3, 2).c_str());
    int year = std::atoi(date.substr(6, 4).c_str());

    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    if (month == 2) {
        if (day > 29) return false;
        // Check for leap year
        if (day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))) {
            return false;
        }
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) {
        return false;
    }

    return true;
}
```
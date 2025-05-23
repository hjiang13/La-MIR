```cpp
#include <string>
#include <stdexcept>
#include <cstdlib>

bool valid_date(const std::string& date_str) {
    if (date_str.size() != 10) {
        return false;
    }

    char first_char = date_str[0] - '0';
    if (first_char > 9) {
        return false;
    }

    // Convert the first part of the date (year)
    char* endptr;
    long year = strtol(date_str.substr(0, 4).c_str(), &endptr, 10);
    if (*endptr != '\0') {
        return false;
    }

    // Convert the second part of the date (month)
    long month = strtol(date_str.substr(5, 2).c_str(), &endptr, 10);
    if (*endptr != '\0' || month < 1 || month > 12) {
        return false;
    }

    // Convert the third part of the date (day)
    long day = strtol(date_str.substr(8, 2).c_str(), &endptr, 10);
    if (*endptr != '\0') {
        return false;
    }

    // Check for valid days in the month
    if (day < 1 || day > 31) {
        return false;
    }
    if (month == 2 && day > 29) {
        return false;
    }
    if (month == 2 && day == 29 && !((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        return false;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }

    return true;
}
```
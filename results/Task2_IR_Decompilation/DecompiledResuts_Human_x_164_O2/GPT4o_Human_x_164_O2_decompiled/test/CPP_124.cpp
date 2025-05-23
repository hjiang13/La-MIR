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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (valid_date("03-11-2000") == true);
    assert (valid_date("15-01-2012") == false);
    assert (valid_date("04-0-2040") == false);
    assert (valid_date("06-04-2020") == true);
    assert (valid_date("01-01-2007") == true);
    assert (valid_date("03-32-2011") == false);
    assert (valid_date("") == false);
    assert (valid_date("04-31-3000") == false);
    assert (valid_date("06-06-2005") == true);
    assert (valid_date("21-31-2000") == false);
    assert (valid_date("04-12-2003") == true);
    assert (valid_date("04122003") == false);
    assert (valid_date("20030412") == false);
    assert (valid_date("2003-04") == false);
    assert (valid_date("2003-04-12") == false);
    assert (valid_date("04-2003") == false);
}

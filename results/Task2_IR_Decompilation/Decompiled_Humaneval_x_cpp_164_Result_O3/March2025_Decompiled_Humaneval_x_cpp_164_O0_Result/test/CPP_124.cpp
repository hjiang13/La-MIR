#include <string>
#include <cstdlib>

bool valid_date(const std::string& date) {
    if (date.length() != 10) {
        return false;
    }

    for (int i = 0; i < 10; ++i) {
        if ((i == 2 || i == 5) && date[i] != '-') {
            return false;
        } else if (i != 2 && i != 5 && (date[i] < '0' || date[i] > '9')) {
            return false;
        }
    }

    int month = std::atoi(date.substr(0, 2).c_str());
    int day = std::atoi(date.substr(3, 2).c_str());
    int year = std::atoi(date.substr(6, 4).c_str());

    if (month < 1 || month > 12) {
        return false;
    }

    if (day < 1 || day > 31) {
        return false;
    }

    if (day == 31) {
        if (month == 4 || month == 6 || month == 9 || month == 11 || month == 2) {
            return false;
        }
    }

    if (day == 30 && month == 2) {
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

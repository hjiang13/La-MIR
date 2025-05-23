```c
#include <string>
#include <cstdlib>

bool valid_date(std::__cxx11::basic_string<char> *str) {
    if (str->size() != 10) {
        return false;
    }

    char first_char = str->at(0);
    if (first_char < '0' || first_char > '9') {
        return false;
    }

    int first_num = first_char - '0';
    int day = std::stoi(str->substr(0, 2));
    if (day < 1 || day > 31) {
        return false;
    }

    int month = std::stoi(str->substr(3, 2));
    if (month < 1 || month > 12) {
        return false;
    }

    int year = std::stoi(str->substr(6, 4));
    if (year < 1900 || year > 9999) {
        return false;
    }

    return true;
}

int main() {
    std::__cxx11::basic_string<char> date = "01/01/2022";
    bool is_valid = valid_date(&date);

    if (is_valid) {
        std::cout << "Valid date" << std::endl;
    } else {
        std::cout << "Invalid date" << std::endl;
    }

    return 0;
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

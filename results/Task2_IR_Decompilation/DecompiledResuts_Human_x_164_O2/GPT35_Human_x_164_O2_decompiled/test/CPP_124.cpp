```c++
#include <string>
#include <cstdlib>
#include <cstring>
#include <stdexcept>

bool valid_date(std::string& str) {
    if (str.size() == 10) {
        char firstChar = str[0];
        if (firstChar >= '0' && firstChar <= '9') {
            int day = std::stoi(str.substr(0, 2));
            int month = std::stoi(str.substr(3, 2));
            int year = std::stoi(str.substr(6, 4));

            if (day > 0 && month > 0 && year > 0) {
                if (day <= 31 && month <= 12 && year >= 1900) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    std::string date = "31/12/2022";
    if (valid_date(date)) {
        std::cout << "Date is valid\n";
    } else {
        std::cout << "Date is invalid\n";
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

```cpp
#include <string>
#include <cstring>

bool valid_date(std::__cxx11::basic_string<char>* str) {
    if (str->size() == 10) {
        for (size_t i = 0; i < str->size(); i++) {
            if (i == 5 || i == 2) {
                continue;
            }
            if (str->at(i) == '-') {
                continue;
            }
            if (str->at(i) < '0' || str->at(i) > '9') {
                return false;
            }
        }
        return true;
    }
    return false;
}

int main() {
    std::__cxx11::basic_string<char> date = "2022-10-31";
    if (valid_date(&date)) {
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

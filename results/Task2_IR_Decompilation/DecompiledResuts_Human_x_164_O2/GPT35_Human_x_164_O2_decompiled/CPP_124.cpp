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
```
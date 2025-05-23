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
```
```c++
#include <string>
#include <cstdlib>

bool valid_date(std::string& date) {
    bool valid = true;
    
    if (date.length() != 10) {
        valid = false;
    } else {
        int day = std::stoi(date.substr(0, 2));
        int month = std::stoi(date.substr(3, 2));
        int year = std::stoi(date.substr(6, 4));
        
        if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2100) {
            valid = false;
        }
    }
    
    return valid;
}
```
```cpp
#include <string>
#include <stdexcept>

void decimal_to_binary(std::string &result, int num) {
    std::string temp;
    if (num == 0) {
        temp = "db";
        result = temp;
        return;
    }

    while (num > 0) {
        temp += std::to_string(num % 2);
        num /= 2;
    }
    
    std::reverse(temp.begin(), temp.end());
    result = temp;
}
```
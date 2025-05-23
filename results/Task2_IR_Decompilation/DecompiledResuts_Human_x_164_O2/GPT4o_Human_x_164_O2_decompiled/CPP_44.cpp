```cpp
#include <cstring>
#include <cstdarg>
#include <string>

void change_base(std::string &str, int base, int num) {
    std::string temp;
    std::string format = "%d";
    
    if (base > 0) {
        int quotient = num / base;
        int remainder = num % base;

        char buffer[32];
        snprintf(buffer, sizeof(buffer), format.c_str(), remainder);
        temp += buffer;

        while (quotient > 0) {
            remainder = quotient % base;
            quotient = quotient / base;
            snprintf(buffer, sizeof(buffer), format.c_str(), remainder);
            temp += buffer;
        }

        str += temp;
    }
}

int main() {
    std::string result;
    change_base(result, 10, 123);
    return 0;
}
```
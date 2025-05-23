#include <string>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>

void decimal_to_binary(std::string &result, int number) {
    std::string temp;
    if (number == 0) {
        result = "0";
        return;
    }
    
    while (number > 0) {
        temp += (number % 2) ? '1' : '0';
        number /= 2;
    }
    std::reverse(temp.begin(), temp.end());
    result = temp;
}

std::string to_xstring(const char* format, ...) {
    std::string result;
    va_list args;
    va_start(args, format);

    int size = vsnprintf(nullptr, 0, format, args);
    if (size < 0) {
        va_end(args);
        throw std::length_error("Formatting error");
    }
    va_end(args);

    result.resize(size + 1); // +1 for null terminator
    va_start(args, format);
    vsnprintf(&result[0], size + 1, format, args);
    va_end(args);

    return result;
}

int main() {
    std::string binary;
    decimal_to_binary(binary, 42);
    printf("Binary: %s\n", binary.c_str());

    std::string formatted = to_xstring("Value: %d", 42);
    printf("%s\n", formatted.c_str());

    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (decimal_to_binary(0) == "db0db");
    assert (decimal_to_binary(32) == "db100000db");
    assert (decimal_to_binary(103) == "db1100111db");
    assert (decimal_to_binary(15) == "db1111db");

}

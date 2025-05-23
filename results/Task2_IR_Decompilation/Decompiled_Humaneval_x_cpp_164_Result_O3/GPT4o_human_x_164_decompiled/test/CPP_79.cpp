#include <string>
#include <cstdarg>
#include <cstring>
#include <iostream>

void decimal_to_binary(std::string& result, int number) {
    if (number == 0) {
        result.append("db0db");
        return;
    }

    std::string temp;
    while (number > 0) {
        temp = (number % 2 ? '1' : '0') + temp;
        number /= 2;
    }
    result.append(temp);
}

void decimal_to_binary(std::string& result, const char* format, ...) {
    va_list args;
    va_start(args, format);
    int number = va_arg(args, int);
    va_end(args);
    decimal_to_binary(result, number);
}

int main() {
    std::string result;
    decimal_to_binary(result, 10); // Example usage
    std::cout << result << std::endl; // Output the result
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

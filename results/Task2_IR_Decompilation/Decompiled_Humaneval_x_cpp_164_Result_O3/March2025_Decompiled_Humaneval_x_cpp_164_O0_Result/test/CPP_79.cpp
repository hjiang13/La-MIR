#include <string>
#include <stdexcept>
#include <cstdarg>
#include <cstdio>

std::string decimal_to_binary(int number) {
    if (number == 0) {
        return "db0db";
    }

    std::string result;
    while (number > 0) {
        int remainder = number % 2;
        result = std::to_string(remainder) + result;
        number /= 2;
    }
    return result + "db";
}

std::string to_string(int value) {
    char buffer[16];
    std::snprintf(buffer, sizeof(buffer), "%d", value);
    return std::string(buffer);
}

void throw_logic_error(const char* message) {
    throw std::logic_error(message);
}

extern "C" void __clang_call_terminate(void* exception) {
    std::terminate();
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (decimal_to_binary(0) == "db0db");
    assert (decimal_to_binary(32) == "db100000db");
    assert (decimal_to_binary(103) == "db1100111db");
    assert (decimal_to_binary(15) == "db1111db");

}

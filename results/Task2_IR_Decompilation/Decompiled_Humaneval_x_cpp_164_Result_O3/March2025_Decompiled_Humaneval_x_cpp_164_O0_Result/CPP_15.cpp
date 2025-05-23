```cpp
#include <string>
#include <stdexcept>
#include <cstdarg>
#include <cstdio>

std::string string_sequence(int n) {
    std::string result = "0";
    for (int i = 1; i <= n; ++i) {
        result += " " + std::to_string(i);
    }
    return result;
}

std::string to_string(int value) {
    char buffer[16];
    std::snprintf(buffer, sizeof(buffer), "%d", value);
    return std::string(buffer);
}

void throw_logic_error(const char* msg) {
    throw std::logic_error(msg);
}

extern "C" void __clang_call_terminate(void* exception) {
    std::terminate();
}
```
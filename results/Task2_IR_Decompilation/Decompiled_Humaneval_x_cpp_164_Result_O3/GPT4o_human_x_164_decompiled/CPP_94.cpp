```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cstdarg>
#include <cstring>

extern "C" {
    void* operator new(std::size_t size) {
        return malloc(size);
    }

    void operator delete(void* ptr) noexcept {
        free(ptr);
    }
}

std::string to_xstring(const char* format, ...) {
    std::string result;
    va_list args;
    va_start(args, format);
    
    char buffer[256];
    vsnprintf(buffer, sizeof(buffer), format, args);
    
    result = buffer;
    va_end(args);
    return result;
}

int skjkasdkd(std::vector<int> vec) {
    std::string str1, str2;
    size_t size = vec.size();
    
    if (size == 0) {
        return 0;
    }

    for (size_t i = 0; i < size; ++i) {
        if (vec[i] > 4) {
            return i;
        }
    }
    
    return 0;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int result = skjkasdkd(vec);
    std::cout << to_xstring("Result: %d", result) << std::endl;
    return 0;
}
```
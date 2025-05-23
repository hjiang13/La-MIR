```cpp
#include <string>
#include <cstring>

void* operator new(std::size_t size) {
    return ::operator new(size);
}

void operator delete(void* ptr) noexcept {
    ::operator delete(ptr);
}

int hex_key(std::string str) {
    std::string temp;
    const char* source = "2357BD";
    size_t length = strlen(source);
    temp.assign(source, length);
    
    int count = 0;
    size_t strLength = str.length();
    
    for (size_t i = 0; i < strLength; ++i) {
        if (i < length && str[i] == temp[i]) {
            count++;
        } else {
            break;
        }
    }
    
    return count;
}
```
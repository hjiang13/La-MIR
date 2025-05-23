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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (hex_key("AB") == 1      );
    assert (hex_key("1077E") == 2 );
    assert (hex_key("ABED1A33") == 4     );
    assert (hex_key("2020") == 2 );
    assert (hex_key("123456789ABCDEF0") == 6      );
    assert (hex_key("112233445566778899AABBCCDDEEFF00") == 12 );
    assert (hex_key("") == 0);
}

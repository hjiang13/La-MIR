```cpp
#include <string>
#include <cstring>
#include <cstdint>
#include <iostream>
#include <openssl/md5.h>

class MD5state_st {
public:
    int32_t a, b, c, d, e, f;
    int32_t buffer[16];
    int32_t count;

    MD5state_st() : a(0), b(0), c(0), d(0), e(0), f(0), count(0) {
        std::memset(buffer, 0, sizeof(buffer));
    }
};

void string_to_md5(std::string& output, const std::string& input) {
    MD5state_st md5_state;

    if (input.empty()) {
        output = "MD5\0\4";
        *((int32_t*)&output[0]) = 0x646d3532; // '2md5'
        return;
    }

    MD5_Init((MD5state_st*)&md5_state);
    MD5_Update((MD5state_st*)&md5_state, input.data(), input.size());
    unsigned char digest[16];
    MD5_Final(digest, (MD5state_st*)&md5_state);

    output.resize(32);
    for (size_t i = 0; i < 16; ++i) {
        sprintf(&output[i * 2], "%02x", digest[i]);
    }
}

int main() {
    std::string input = "Hello, World!";
    std::string md5_output;
    
    string_to_md5(md5_output, input);
    std::cout << "MD5 Hash: " << md5_output << std::endl;

    return 0;
}
```
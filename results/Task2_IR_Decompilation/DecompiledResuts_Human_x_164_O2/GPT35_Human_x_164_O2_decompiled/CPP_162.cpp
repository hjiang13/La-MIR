```c++
#include <string>
#include <cstring>

struct MD5state_st {
    int32_t data[8];
};

void string_to_md5(std::string& output, const std::string& input) {
    MD5state_st state;
    MD5_Init(&state);
    MD5_Update(&state, input.c_str(), input.size());
    
    unsigned char result[16];
    MD5_Final(result, &state);
    
    output.clear();
    output.resize(32);
    
    for (int i = 0; i < 16; ++i) {
        sprintf(&output[i * 2], "%02x", result[i]);
    }
}
```
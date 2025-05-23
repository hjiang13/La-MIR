```cpp
#include <string>
#include <cstring>
#include <cstdint>
#include <cstdlib>

struct MD5state_st {
    int32_t state[4];
    int32_t count[2];
    uint8_t buffer[64];
};

extern "C" {
    void MD5_Init(MD5state_st* context);
    void MD5_Update(MD5state_st* context, const uint8_t* input, uint64_t inputLen);
    void MD5_Final(uint8_t* digest, MD5state_st* context);
}

std::string string_to_md5(std::string& input) {
    MD5state_st state;
    uint8_t digest[16];
    MD5_Init(&state);
    MD5_Update(&state, reinterpret_cast<const uint8_t*>(input.c_str()), input.size());
    MD5_Final(digest, &state);
    
    std::string result;
    result.resize(32);
    
    for (size_t i = 0; i < 16; ++i) {
        snprintf(&result[i * 2], 3, "%02x", digest[i]);
    }
    
    return result;
}
```
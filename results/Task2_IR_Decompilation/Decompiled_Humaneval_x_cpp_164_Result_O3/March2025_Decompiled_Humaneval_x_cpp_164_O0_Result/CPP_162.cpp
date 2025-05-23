```cpp
#include <string>
#include <openssl/md5.h>

std::string string_to_md5(const std::string& input) {
    if (input.empty()) {
        return "None";
    }

    MD5state_st md5_state;
    MD5_Init(&md5_state);
    MD5_Update(&md5_state, input.c_str(), input.length());

    unsigned char digest[16];
    MD5_Final(digest, &md5_state);

    std::string result;
    for (int i = 0; i < 16; ++i) {
        char buf[3];
        snprintf(buf, sizeof(buf), "%02x", digest[i]);
        result += buf;
    }

    return result;
}
```
```cpp
#include <string>
#include <cstring>
#include <iostream>
#include <openssl/md5.h>

void string_to_md5(std::string& result, const std::string& input) {
    if (input.length() == 0) {
        result = "None";
        return;
    }

    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, input.c_str(), input.length());

    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5_Final(digest, &ctx);

    char hex[MD5_DIGEST_LENGTH * 2 + 1];
    for (int i = 0; i < MD5_DIGEST_LENGTH; ++i) {
        sprintf(&hex[i * 2], "%02x", (unsigned int)digest[i]);
    }
    result = std::string(hex);
}
```
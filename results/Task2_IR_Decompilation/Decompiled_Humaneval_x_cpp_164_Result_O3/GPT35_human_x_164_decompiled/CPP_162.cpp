```c
#include <string>
#include <cstring>
#include <openssl/md5.h>

void string_to_md5(std::string& output, const std::string& input) {
    if (input.empty()) {
        output = "";
        return;
    }

    unsigned char result[MD5_DIGEST_LENGTH];
    MD5((const unsigned char*)input.c_str(), input.length(), result);

    char md5_str[MD5_DIGEST_LENGTH * 2 + 1];
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(&md5_str[i * 2], "%02x", (unsigned int)result[i]);
    }

    output = std::string(md5_str);
}

int main() {
    std::string input = "Hello, World!";
    std::string output;
    string_to_md5(output, input);

    std::cout << "MD5 hash of '" << input << "': " << output << std::endl;

    return 0;
}
```
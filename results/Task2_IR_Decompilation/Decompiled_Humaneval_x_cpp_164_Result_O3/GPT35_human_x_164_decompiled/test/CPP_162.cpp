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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (string_to_md5("Hello world") == "3e25960a79dbc69b674cd4ec67a72c62");
    assert (string_to_md5("") == "None");
    assert (string_to_md5("A B C") == "0ef78513b0cb8cef12743f5aeb35f888");
    assert (string_to_md5("password") == "5f4dcc3b5aa765d61d8327deb882cf99");
}

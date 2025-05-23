```c++
#include <string>
#include <iostream>
#include <openssl/md5.h>

std::string string_to_md5(const std::string& input) {
    MD5_CTX context;
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5_Init(&context);
    MD5_Update(&context, input.c_str(), input.length());
    MD5_Final(digest, &context);
    
    std::string output;
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        char buf[3];
        sprintf(buf, "%02x", digest[i]);
        output += buf;
    }
    
    return output;
}

int main() {
    std::string input = "Hello, World!";
    std::string md5_hash = string_to_md5(input);
    std::cout << "MD5 hash of '" << input << "': " << md5_hash << std::endl;
    
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

#include <cstring>
#include <string>
#include <iostream>
#include <openssl/md5.h>

class MD5state {
public:
    int state[4];
    int count[2];
    unsigned char buffer[64];
};

void string_to_md5(std::string &output, const std::string &input) {
    MD5state md5;
    MD5_Init((MD5_CTX *)&md5);
    
    MD5_Update((MD5_CTX *)&md5, input.c_str(), input.size());

    unsigned char digest[16];
    MD5_Final(digest, (MD5_CTX *)&md5);

    output.resize(32);
    for (int i = 0; i < 16; i++) {
        sprintf(&output[i * 2], "%02x", (unsigned int)digest[i]);
    }
}

int main() {
    std::string input = "Hello, World!";
    std::string output;
    string_to_md5(output, input);
    std::cout << "MD5: " << output << std::endl;
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

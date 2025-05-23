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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (string_to_md5("Hello world") == "3e25960a79dbc69b674cd4ec67a72c62");
    assert (string_to_md5("") == "None");
    assert (string_to_md5("A B C") == "0ef78513b0cb8cef12743f5aeb35f888");
    assert (string_to_md5("password") == "5f4dcc3b5aa765d61d8327deb882cf99");
}
